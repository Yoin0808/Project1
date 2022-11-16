#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	getline(cin, str);
	int i = 0;
	int count = 0;
	while (str[i] != '\0') {
		if (str[i] != '#') {
			count++;
		}
		i++;
	}
	cout << count;
}