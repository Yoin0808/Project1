#include<iostream>
using namespace std;
void MIN(int a[],int n) {
	int i, j;
	int index;
	int temp;
	for (i = 0; i < n - 1; i++) {
		index = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[index]) index = j;//标记下标
		}
		if (index != i) {
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}
	}
	
	
}
int main() {
	char ch;
	int a[100] = { 0 };
	int n = 0;
	do {
		cin >> a[n];
		n++;
	} while ((ch = getchar()) == ' ');
	for (int i = 0; i < n; i++) {
		MIN(a, n);
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}