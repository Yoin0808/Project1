#include  <iostream>
using  namespace  std;

typedef  int  DataType;
typedef  struct  node {
    DataType  data;
    node* next;
}node;

//尾插法构造单链表
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
//八进制A加八进制B，结果存在链表A中
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


    //A、B等长
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


    //A比B短
    if (p->next == NULL && q->next != NULL) {
        sum = p->data + q->data + flag;
        //将A中的最后一个结点元素和B中同位置的元素相加后对8取余，并将余数放入A中的最后一个结点的数据域。
        p->data = sum % 8;
        //记录好此时p、q所分别指向的结点元素相加后是否有进位。
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


    //A比B长
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