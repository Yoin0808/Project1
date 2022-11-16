#include  <iostream>
using  namespace  std;
const  int  MaxSize = 100;
typedef  int  DataType;
DataType  data[MaxSize];
int  length;

void  deleteList(DataType  elem)
{
	DataType  data[MaxSize];
	int acount = 0;
	int i, j;
	for (i = 0; i < length; i++) {
		if (data[i] == elem) {
			for (j = i; j < length; j++) {
				data[j] = data[j + 1];
			}
			acount++;
			i--;
		}
	}
	length = length - acount;
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
	deleteList(x);
	show();
	return  0;
}