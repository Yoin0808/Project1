#include<iostream>
#include<string>
using namespace std;
void preorder(int i,char s[]) {
	if (s[i] == '#') return;
	else {
		cout << s[i]<<" ";
		preorder(i * 2, s);//若根节点为1，左子树为2i，右子树为2i+1
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
		s[i + 1] = str[i];//舍去下标为0的
		i++;
	}
	preorder(1, s);
}
