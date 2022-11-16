#include<iostream>
using namespace std;
int main(){
	char ch;
	int a[10] = { 0 };
	int n = 0;
	do{
		cin >> a[n];
		n++;
	}while ((ch = getchar()) != '\n');
	int k;
	cin >> k;
	int temp,j;
	for (int i = 1; i < n; i++) {
		temp = a[i];
		for (j = i - 1; j >= 0&&(a[j] > temp); j--) {
				a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
	for (int i = 0; i < k; i++) {
		cout << a[i] << " ";
	}
}