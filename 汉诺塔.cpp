#include<iostream>
using namespace std;
void hanor(int n, char from, char help, char to) {
	/*三个位置分别为：起始位置，辅助位置，目标位置*/
	/*递归运算从底部开始，输出则从顶部开始*/
	if (n == 1) {
		cout << from << "->" << to << endl;
		return;
	}
	hanor(n - 1, from, to, help);//前n-1层看成一个整体
	cout << from << "->" << to << endl;
	hanor(n - 1, help, from, to);
}
int main()
{
	int n;
	cin >> n;
	hanor(n, 'A', 'B', 'C');
}
