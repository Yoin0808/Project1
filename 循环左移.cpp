#include <iostream>
using  namespace  std;
void  reverseArr(int  A[], int  start, int  rear) {//�����㷨
	int temp;
	int len = rear - start + 1;
	for (int i = 0; i < len / 2; i++)
	{
		temp = A[start + i];
		A[start + i] = A[rear - i];
		A[rear - i] = temp;
	}
}
void  leftCir(int  A[], int  n, int  k) {
	if (k <= 0 || k >= n)
		cout << "ERROR" << endl;
	else {
		/*��������⿴���ǰ�����ABת��������BA
		��A���������ǰ i ��Ԫ�أ�B�������������µ� n �C i ��Ԫ�أ���
		�Ƚ�A����õ�A'���ٽ�B����õ�B'��
		�������A'B'����õ�(A'B')' = BA*/
		reverseArr(A, 0, k - 1);
		reverseArr(A, k, n - 1);
		reverseArr(A, 0, n - 1);
	}
}
void  show(int  A[], int  n) {
	for (int i = 0; i < n; ++i)
		cout << A[i] << "  ";
	cout << endl;
}
int  main()
{
	int  n, p;
	cin >> n >> p;
	int  a[100];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	leftCir(a, n, p);
	show(a, n);
	return  0;
}