#include  <iostream>
using  namespace  std;

template  <class  DataType>
struct  node {
    DataType  data;
    node<DataType>* next;
};

template  <class  DataType>
class  linkList {
public:
    linkList();
    ~linkList();
    node<DataType>* getFirst();
    void  reversePrint(node<DataType>* p);
private:
    node<DataType>* first;
};

template  <class  DataType>
linkList<DataType>::linkList()
{
    first = new  node<DataType>;
    first->next = NULL;
    node<DataType>* rear = first;
    int  n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        DataType  elem;
        cin >> elem;
        node<DataType>* s = new  node<DataType>;
        s->data = elem;
        s->next = NULL;
        rear->next = s;
        rear = s;
    }
}
template  <class  DataType>
linkList<DataType>::~linkList()
{
    node<DataType>* p;
    while (first != NULL) {
        p = first;
        first = first->next;
        delete  p;
    }
}

template  <class  DataType>
node<DataType>* linkList<DataType>::getFirst()
{
    return  first;
}

template  <class  DataType>
void  linkList<DataType>::reversePrint(node<DataType>* p)
{
    if (p != NULL) {
        reversePrint(p->next);
        cout << p->data << " ";
    }

}
int  main()
{
    linkList<int>  L;
    node<int>* p = L.getFirst()->next;
    if (p == NULL)
        cout << "Empty" << endl;
    else
        L.reversePrint(p);
    L.~linkList();
    return  0;
}
