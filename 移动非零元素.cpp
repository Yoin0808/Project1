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
	for (int i = 0; i < n; i++) {//�Ƚ�n�Σ�����ð��
		for (int j = 0; j < n - 1; j++) {//������ұ߽���λ��
			if (arr[j] == 0) {
				change(&arr[i], &arr[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}