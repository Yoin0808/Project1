#include  <iostream>
using  namespace  std;
void  getMax(int  A[], int  n, int& fMax, int& sMax) {
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (A[j] < A[j + 1]) {
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
	fMax = A[0];
	sMax = A[1];
}
int  main()
{
	int  n, maxV, nMax;
	cin >> n;
	int  a[100];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	getMax(a, n, maxV, nMax);
	cout << maxV << "  " << nMax << endl;
	return  0;
}