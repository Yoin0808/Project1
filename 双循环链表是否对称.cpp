#include  <iostream>
using  namespace  std;

typedef  int  DataType;
typedef  struct  node {
    DataType  data;
    node* next, * prior;
}node;
node* first;

void  init()
{
    first = new  node;
    first->next = NULL;
    first->prior = NULL;
    node* rear = first;
    DataType  elem;
    while (cin >> elem) {
        node* s = new  node;
        s->data = elem;
        s->next = NULL;
        s->prior = rear;
        rear->next = s;
        rear = s;
    }
    rear->next = first;
    first->prior = rear;
}
bool  equalDulList()
{
    node* p = first->next;
    node* q = first->prior;
    while (p != q && p->prior != q) 
    {
        if (p->data == q->data)
        {
            p = p->next;//从前往后走
            q = q->prior;//从后往前走
            return true;
        }
        else return false;
    }
    return true;//就一个元素
}
void  show()
{
    node* p = first->next;
    while (p != first) {
        cout << p->data << "  ";
        p = p->next;
    }
    cout << endl;
}
int  main()
{
    init();
    //show();
    bool  res = equalDulList();
    if (res)  cout << "YES" << endl;
    else  cout << "NO" << endl;
    return  0;
}