#include  <iostream>
using  namespace  std;

const  int  MaxSize = 100;
typedef  int  DataType;
DataType  data[MaxSize];
int  length;

void  reverseList()
{
	DataType  data[MaxSize];
	int temp;
	for (int i = 0; i < length / 2; i++) {
		temp = data[i];
		data[i] = data[length - 1 - i];
		data[length - 1 - i] = temp;
	}
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
	reverseList();
	show();
	return  0;
}