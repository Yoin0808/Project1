#include <iostream>
using namespace std;
struct BiNode {
	char data;
	BiNode* Lchild;
	BiNode* Rchild;
};
class BiTree {
public:
	BiTree() {root = Creat();}

	~BiTree() {Release(root);}
	int Depth() {return Depth(root);}

private:
	BiNode* Creat();
	void Release(BiNode* bt);
	int Depth(BiNode* bt);
	BiNode* root;
};
BiNode* BiTree::Creat() {
	BiNode* bt;
	char ch = getchar();
	if (ch == '#')bt = nullptr;
	else {
		bt = new BiNode;
		bt->data = ch;
		bt->Lchild = Creat();
		bt->Rchild = Creat();
	}
	return bt;
}
void BiTree::Release(BiNode* bt) {
	if (bt == NULL)return;
	else {
		Release(bt->Lchild);
		Release(bt->Rchild);
		delete bt;
	}
}
int BiTree::Depth(BiNode* bt) {
	int i = 0, j = 0;
	if (bt == NULL)return 0;
	else {
		i = Depth(bt->Lchild);
		j = Depth(bt->Rchild);
	}
	if (i >= j) {
		return i + 1;
	}
	else{
		return j + 1;
	}
}
int main() {
	BiTree t;
	cout << t.Depth();
	return 0;
}
