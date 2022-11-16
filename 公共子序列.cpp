#include <iostream>
#include <string>
using namespace std;
int mat(string s, string t);
int main()
{
	string s;
	string t;
	string m;
	getline(cin, s);
	getline(cin, t);
	getline(cin, m);
	int a = mat(s, m);//比较3是否是1的子序列
	int b = mat(t, m);//比较3是否是2的子序列
	if (a && b) cout << "YES";
	else cout << "NO";

}
int mat(string s, string t) {//判断是否是子串的函数
	int i = 0, j = 0;
	while ((s[i] != '\0') && (t[j] != '\0')) {
		if (s[i] == t[j]) {
			i++;
			j++;
		}
		else {
			i++;//i继续往前走，只需要主串中含有模式中的字符就可以，无需每次回溯
			/*
			a b c d a b d
			
			a b d
			第三个不符合，模式第三个继续和主串第4个比，依次往下，直至找到
			*/
		}
	}
	if (t[j] == '\0') return 1;//返回值为1
	else return 0;
}