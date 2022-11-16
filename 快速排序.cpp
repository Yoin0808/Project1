#include<iostream>
using namespace std;
int part(int a[], int first,int last) {
	int i = first, j = last, temp;
	while (i<j)
	{
		while (i < j && a[i] <= a[j]) j--;
		if (i < j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
		}
		while (i < j && a[i] <= a[j]) i++;
		if (i < j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			j--;
		}
	}
	return i;
}
void quick(int a[], int first, int last) {
	if (first >= last) return;
	else{
	int mid = part(a, first, last);
	quick(a, first, mid - 1);
	quick(a, mid+1, last);}
}
int main() {
	int n;
	int a[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m = part(a, 0, n - 1);
	quick(a, 0, n-1);
	
	cout << m+1 << " ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}