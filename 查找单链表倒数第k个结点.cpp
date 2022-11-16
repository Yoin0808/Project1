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
	node<DataType>* reverseFindK(int  k);
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
node<DataType>* linkList<DataType>::reverseFindK(int  k)
{
	node<DataType>* p = NULL;
	node<DataType>* q = NULL;
	p = first->next;
	q = first->next;
	int count = 1;
	int length = 1;
	while (q != NULL) {
		q = q->next;
		length++;
	}
	while (p != NULL) {
		if (length < k) return NULL;
		if (count == length - k) {
			return p;
		}
		p = p->next;
		count++;
	}
}
int  main()
{
	linkList<int>  L;
	int  k;
	cin >> k;
	node<int>* p = L.reverseFindK(k);
	if (p == NULL)
		cout << "Not  Found" << endl;
	else
		cout << p->data << endl;
	L.~linkList();
	return  0;
}