#include<iostream>
#include<string>
using namespace std;
void preorder(int i,char s[]) {
	if (s[i] == '#') return;
	else {
		cout << s[i]<<" ";
		preorder(i * 2, s);//�����ڵ�Ϊ1��������Ϊ2i��������Ϊ2i+1
		preorder(i * 2 + 1, s);
	}
}
int main() {
	string str;
	getline(cin, str);
	char s[100];
	int i = 0;
	for (int j = 0; j < 100; j++) {
		s[j] = '#';
	}	
	while (str[i] != '\0') {
		s[i + 1] = str[i];//��ȥ�±�Ϊ0��
		i++;
	}
	preorder(1, s);
}
