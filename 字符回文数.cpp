#include  <iostream>
#include  <string>
using  namespace  std;

bool  judge(string  str) {
	int len = 0;
	for (int i = 0; i < 100; i++) {
		if (str[i] < 65 || str[i]>122) {
			break;
		}
		len++;//计算字符串的大小
	}
	for (int i = 0; i < len; i++) {
		if (str[i] != str[len - i - 1]) {
			return false;
		}//回文数
		/*
		此处将反面作为判断，因为正面必须所有字符都满足才可以，稍微麻烦
		*/
	}
	return true;
}
int  main()
{
	string  s;
	getline(cin, s);
	bool  res = judge(s);
	if (res)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return  0;
}