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
	int a = mat(s, m);//�Ƚ�3�Ƿ���1��������
	int b = mat(t, m);//�Ƚ�3�Ƿ���2��������
	if (a && b) cout << "YES";
	else cout << "NO";

}
int mat(string s, string t) {//�ж��Ƿ����Ӵ��ĺ���
	int i = 0, j = 0;
	while ((s[i] != '\0') && (t[j] != '\0')) {
		if (s[i] == t[j]) {
			i++;
			j++;
		}
		else {
			i++;//i������ǰ�ߣ�ֻ��Ҫ�����к���ģʽ�е��ַ��Ϳ��ԣ�����ÿ�λ���
			/*
			a b c d a b d
			
			a b d
			�����������ϣ�ģʽ������������������4���ȣ��������£�ֱ���ҵ�
			*/
		}
	}
	if (t[j] == '\0') return 1;//����ֵΪ1
	else return 0;
}