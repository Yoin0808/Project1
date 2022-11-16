#include <iostream>
#include <string>
using namespace std;
int main()
{
	int num[100];
	int i = 0;
	while (i < 100)
	{
		cin >> num[i];
		i++;
		if (cin.get() == '\n') break;
	}
	cout << i << endl;
	for (int k = 0; k < i; k++)
	{
		cout << num[k] << endl;
	}
}