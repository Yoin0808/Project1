#include <iostream>
#include<string>
using namespace std;
int main() {
	string str;
	char stack[1000] = { 0 };
	int top = -1;
	cin >> str;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			stack[++top] = str[i];
		}
		else if (str[i] == ')') {
			if (stack[top] == '(')
			{
				top--;
			}
			else { cout << "NO"; return 0; }
		}
		else if (str[i] == ']') {
			if (stack[top] == '[')
			{
				top--;
			}
			else { cout << "NO"; return 0; }
		}
		else if (str[i] == '{') {
			if (stack[top] == '}')
			{
				top--;
			}
			else { cout << "NO"; return 0; }
		}
	}
	if (top == -1) { cout << "YES"; return 0; }
	else { cout << "NO"; return 0; }
}