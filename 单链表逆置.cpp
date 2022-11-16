#include  <iostream>
using  namespace  std;

typedef  int  DataType;
typedef  struct  node {
	DataType  data;
	node* next;
}node;
node* first;
int  length;

void  init()
{
	first = new  node;
	first->next = NULL;
	node* rear = first;
	cin >> length;
	for (int i = 0; i < length; ++i) {
		DataType  elem;
		cin >> elem;
		node* s = new  node;
		s->data = elem;
		s->next = NULL;
		rear->next = s;
		rear = s;
	}
}
void  reverseList()
{
	node* q = new node();
	node* p = first->next;
	first->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = first->next;
		first->next = p;
		p = q;
	}

}
void  show()
{
	node* p = first->next;
	while (p != NULL) {
		cout << p->data << "  ";
		p = p->next;
	}
	cout << endl;
}
int  main()
{
	init();
	reverseList();
	show();
	return  0;
}