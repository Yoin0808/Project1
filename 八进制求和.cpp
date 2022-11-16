#include  <iostream>
using  namespace  std;

typedef  int  DataType;
typedef  struct  node {
    DataType  data;
    node* next;
}node;

//β�巨���쵥����
void  init(node*& first, int  len)
{
    first = NULL;
    node* rear;
    for (int i = 0; i < len; ++i) {
        DataType  elem;
        cin >> elem;
        node* s = new  node;
        s->data = elem;
        s->next = NULL;
        if (first == NULL) {
            first = s;
            rear = first;
        }
        else {
            rear->next = s;
            rear = s;
        }
    }
}
//�˽���A�Ӱ˽���B�������������A��
void  add(node* A, node* B)
{
    node* p = A, * q = B;
    int flag = 0;//
    int sum = 0;
    while (p->next != NULL && q->next != NULL) {
        sum = p->data + q->data + flag;
        p->data = sum % 8;
        flag = sum / 8;
        p = p->next;
        q = q->next;
    }


    //A��B�ȳ�
    if (p->next == NULL && q->next == NULL) {
        sum = p->data + q->data + flag;
        p->data = sum % 8;
        flag = sum / 8;
        if (flag == 1) {
            node* s = new node;
            s->data = flag;
            s->next = NULL;
            p->next = s;
        }
    }


    //A��B��
    if (p->next == NULL && q->next != NULL) {
        sum = p->data + q->data + flag;
        //��A�е����һ�����Ԫ�غ�B��ͬλ�õ�Ԫ����Ӻ��8ȡ�࣬������������A�е����һ������������
        p->data = sum % 8;
        //��¼�ô�ʱp��q���ֱ�ָ��Ľ��Ԫ����Ӻ��Ƿ��н�λ��
        flag = sum / 8;
        while (q->next != NULL) {
            node* s = new node;
            sum = q->next->data + flag;
            s->data = sum % 8;
            flag = sum / 8;
            s->next = NULL;
            p->next = s;
            p = p->next;
            q = q->next;
        }


        if (flag == 1 && q->next == NULL) {
            node* s = new node;
            s->data = flag;
            s->next = NULL;
            p->next = s;
        }
    }


    //A��B��
    if (q->next == NULL && p->next != NULL) {
        sum = p->data + q->data + flag;
        p->data = sum % 8;
        flag = sum / 8;
        while (p->next != NULL) {
            if (flag == 1) {
                sum = p->next->data + flag;
                p->next->data = sum % 8;
                flag = sum / 8;
                p = p->next;
            }
            else
                break;
        }


        if (flag == 1 && p->next == NULL) {
            node* s = new node;
            s->data = flag;
            s->next = NULL;
            p->next = s;
        }
    }
}
void  reverseList(node*& first)
{
    node* q = first, * p = first;
    if (first == NULL) {
        return;
    }
    else {
        while (p->next != NULL) {
            p = p->next;
        }
        first = p;
        p = q->next;
        while (q != first) {
            q->next = first->next;
            first->next = q;
            q = p;
            p = p->next;
        }
    }

}
void  show(node* first)
{
    node* p = first;
    if (p == NULL)  cout << "Empty";
    else {
        while (p != NULL) {
            
            cout << p->data;
            p = p->next;
        }
        cout << endl;
    }
}
int  main()
{
    node* A, * B;
    int  aLen, bLen;
    cin >> aLen;
    init(A, aLen);
    cin >> bLen;
    init(B, bLen);

    reverseList(A);
    reverseList(B);

    add(A, B);
    reverseList(A);
    show(A);
    return  0;
}