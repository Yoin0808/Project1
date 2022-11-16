#include <iostream>
using namespace std;
int change(int *a,int *b) {
	int t;
			t = *a;
			*a = *b;
			*b = t;

			return *a;
}
int main() {
	int n;
	cin >> n;
	int arr[100];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {//比较n次，类似冒泡
		for (int j = 0; j < n - 1; j++) {//左边与右边交换位置
			if (arr[j] == 0) {
				change(&arr[i], &arr[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}