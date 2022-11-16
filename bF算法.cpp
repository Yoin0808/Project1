#include <iostream>
#include <string>
using namespace std;
int bs(string s, string t);
int main()
{
	string s;
	string t;
	getline(cin, s);
	getline(cin, t);
	cout << bs(s, t);
}
int bs(string s, string t) {
	int i = 0, j = 0;
	while ((s[i] !='\0') && (t[j] !='\0')) {
		if (s[i] == t[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
			/*
			a b c d a b d e
			a b d
			主1、主2与模式1、模式2均匹配，主3与模式3不匹配
			所有主串从第二个（b）开始和字串第一个比较
			*/
		}
	}
	if (t[j] == '\0') return i - j + 1;
	else return 0;
}