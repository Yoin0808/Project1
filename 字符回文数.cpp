#include  <iostream>
#include  <string>
using  namespace  std;

bool  judge(string  str) {
	int len = 0;
	for (int i = 0; i < 100; i++) {
		if (str[i] < 65 || str[i]>122) {
			break;
		}
		len++;//�����ַ����Ĵ�С
	}
	for (int i = 0; i < len; i++) {
		if (str[i] != str[len - i - 1]) {
			return false;
		}//������
		/*
		�˴���������Ϊ�жϣ���Ϊ������������ַ�������ſ��ԣ���΢�鷳
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