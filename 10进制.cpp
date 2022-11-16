#include<iostream>
#include<stack>
using  namespace  std;

int main()
{
	int n, d;
	int a[100] = { 0 };
	cin >> n >> d;
	int i = 0, count = 0;
	if (d == 16) {
		while (n != 0) {
			a[i] = n % d;
			n = n / d;
			i++;
		}
		count = i;
		for (i = count - 1; i >= 0; i--) {
			if (a[i] > 9) {
				switch (a[i])
				{
				case 10:cout << "A"; break;
				case 11:cout << "B"; break;
				case 12:cout << "C"; break;
				case 13:cout << "D"; break;
				case 14:cout << "E"; break;
				case 15:cout << "F"; break;
				}
			}
			if (a[i] <= 9) cout << a[i];
		}
	}
	if (d == 15) {
		while (n != 0) {
			a[i] = n % d;
			n = n / d;
			i++;
		}
		count = i;
		for (i = count - 1; i >= 0; i--) {
			if (a[i] > 9) {
				switch (a[i])
				{
				case 10:cout << "A"; break;
				case 11:cout << "B"; break;
				case 12:cout << "C"; break;
				case 13:cout << "D"; break;
				case 14:cout << "E"; break;
				}
			}
			if (a[i] <= 9) cout << a[i];
		}
	}
	if (d == 14) {
		while (n != 0) {
			a[i] = n % d;
			n = n / d;
			i++;
		}
		count = i;
		for (i = count - 1; i >= 0; i--) {
			if (a[i] > 9) {
				switch (a[i])
				{
				case 10:cout << "A"; break;
				case 11:cout << "B"; break;
				case 12:cout << "C"; break;
				case 13:cout << "D"; break;
				}
			}
			if (a[i] <= 9) cout << a[i];
		}
	}
	if (d == 13) {
		while (n != 0) {
			a[i] = n % d;
			n = n / d;
			i++;
		}
		count = i;
		for (i = count - 1; i >= 0; i--) {
			if (a[i] > 9) {
				switch (a[i])
				{
				case 10:cout << "A"; break;
				case 11:cout << "B"; break;
				case 12:cout << "C"; break;
				}
			}
			if (a[i] <= 9) cout << a[i];
		}
	}
	if (d == 12) {
		while (n != 0) {
			a[i] = n % d;
			n = n / d;
			i++;
		}
		count = i;
		for (i = count - 1; i >= 0; i--) {
			if (a[i] > 9) {
				switch (a[i])
				{
				case 10:cout << "A"; break;
				case 11:cout << "B"; break;
				}
			}
			if (a[i] <= 9) cout << a[i];
		}
	}
	if (d == 11) {
		while (n != 0) {
			a[i] = n % d;
			n = n / d;
			i++;
		}
		count = i;
		for (i = count - 1; i >= 0; i--) {
			if (a[i] > 9) {
				switch (a[i])
				{
				case 10:cout << "A"; break;
				}
			}
			if (a[i] <= 9) cout << a[i];
		}
	}
	if (d <= 10) {
		while (n != 0) {
			a[i] = n % d;
			n = n / d;
			i++;
		}
		count = i;
		for (i = count - 1; i >= 0; i--) {
			cout << a[i];
		}
	}
	return 0;
}