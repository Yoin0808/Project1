#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	getline(cin, str);
	int i = 0;
	while (str[i] != '\0') {
		if(str[i]!='#'){
			if (str[i + 1] == '#' && str[i + 2] == '#') {
				cout << str[i] << " ";
			}
		}
		i++;
	}
}