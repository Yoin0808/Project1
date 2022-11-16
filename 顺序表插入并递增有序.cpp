#include  <iostream>
using  namespace  std;

const  int  MaxSize = 100;
typedef  int  DataType;
DataType  data[MaxSize];
int  length = 0;

void  insertList(DataType  elem)
{
	DataType  data[MaxSize];
	int i;
	for (i = 0; i < length; i++)
	{
		if (data[i] > elem)
			break;
	}
	for (int j = length - 1; j >= i; j--) {
		data[j + 1] = data[j];
	}
	data[i] = elem;
	length++;
}
void  show()
{
	DataType  data[MaxSize];
	for (int i = 0; i < length; ++i)
		cout << data[i] << "  ";
	cout << endl;
}
int  main()
{
	DataType  data[MaxSize];
	cin >> length;
	for (int i = 0; i < length; ++i)
		cin >> data[i];
	DataType  x;
	cin >> x;
	insertList(x);
	show();
	return  0;
}