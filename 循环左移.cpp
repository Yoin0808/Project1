#include <iostream>
using  namespace  std;
void  reverseArr(int  A[], int  start, int  rear) {//倒置算法
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
		/*将这个问题看作是把数组AB转换成数组BA
		（A代表数组的前 i 个元素，B代表数组中余下的 n – i 个元素），
		先将A置逆得到A'，再将B置逆得到B'，
		最后将整个A'B'置逆得到(A'B')' = BA*/
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