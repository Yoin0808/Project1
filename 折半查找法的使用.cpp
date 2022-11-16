#include<iostream>
using namespace std;
int main(){
	int n, k;
	int A[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf_s("%d,", &A[i]);
	}
	cin >> k;
	int first = 0, last = n - 1;
	int mid[10] = {0};
	int j = 0;
	int flag=0;
	while (first <= last) {
		mid[j] = (first + last) / 2;
		if (A[mid[j]] < k) {
			first = mid[j] + 1;
			
		}
		if (A[mid[j]] > k) {
			last = mid[j] - 1;
		}
		if (A[mid[j]] == k) {
			cout << mid[j]<<endl;
			flag = 1;
			break;
		}	
		j++;
	}
	if (flag == 0) {
		cout << "no" << endl;
		for (int i = 0; i < j; i++) {
			if (i == j-1) {
				cout << A[mid[i]];
			}
			else
			{
				cout << A[mid[i]] << ",";
			}
		}
	}
	if (flag == 1) {
		for (int i = 0; i <= j; i++) {
			if (i == j) {
				cout << A[mid[i]];
			}
			else
			{
				cout << A[mid[i]] << ",";
			}
		}
	}
}