#include<iostream>
using namespace std;
void hanor(int n, char from, char help, char to) {
	/*����λ�÷ֱ�Ϊ����ʼλ�ã�����λ�ã�Ŀ��λ��*/
	/*�ݹ�����ӵײ���ʼ�������Ӷ�����ʼ*/
	if (n == 1) {
		cout << from << "->" << to << endl;
		return;
	}
	hanor(n - 1, from, to, help);//ǰn-1�㿴��һ������
	cout << from << "->" << to << endl;
	hanor(n - 1, help, from, to);
}
int main()
{
	int n;
	cin >> n;
	hanor(n, 'A', 'B', 'C');
}
