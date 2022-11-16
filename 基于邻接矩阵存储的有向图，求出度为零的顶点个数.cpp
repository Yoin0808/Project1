#include<iostream>
using namespace std;
int search(string c,string str[]) {
	for (int i = 0; i < 10; i++) {
		if (str[i] == c) {
			return i;
		}
	}
}
int main(){
	string m, n;
	int value;
	int vertexnum, edgenum;
	cin >> vertexnum >> edgenum;
	string vertex[10];
	int edge[10][10];
	for (int i = 0; i < vertexnum; i++) {
		cin >> vertex[i];
	}
	for (int i = 0; i < vertexnum; i++) {
		for (int j = 0; j < vertexnum; j++) {
			edge[i][j] = 0;
		}
	}
	for (int k = 0; k < edgenum; k++) {
		cin >> m >> n >> value;
		edge[search(m, vertex)][search(n, vertex)] = value;
	}
	int cnt = 0;	
	for (int i = 0; i < vertexnum; i++) {
		int flag = 0;
		for (int j = 0; j < vertexnum; j++) {
			if (edge[i][j] != 0) {
				flag = 1;
				break;
			}
		}

		if (flag == 0) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}