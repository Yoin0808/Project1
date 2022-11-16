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
	void  Delete();
	void  show();
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
void  linkList<DataType>::Delete()
{
	node<DataType>* p = first->next;
	while (p != NULL && p->next != NULL)//遍历链表，查看是否有与p值域相同的结点
	{
		if (p->data == p->next->data)//有,删除s
		{
			node<DataType>* s = p->next;//生成新结点s，指向重复结点
			p->next = s->next;//修改指针，此时q->next是s的下一个结点，下一轮继续判断
			delete s;
		}
		else//不同，判断下一个结点
			p = p->next;
	}
}

template  <class  DataType>
void  linkList<DataType>::show()
{
	node<DataType>* p = first->next;
	if (p == NULL)  cout << "Empty";
	else {
		while (p != NULL) {
			cout << p->data << "  ";
			p = p->next;
		}
		cout << endl;
	}
}
int  main()
{
	linkList<int>  L;
	L.Delete();
	L.show();
	L.~linkList();
	return  0;
}