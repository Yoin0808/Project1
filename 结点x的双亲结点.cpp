#include <iostream>
using namespace std;
struct BiNode {
	char data;
	BiNode* Lchild;
	BiNode* Rchild;
};
class BiTree {
public:
	BiTree() { root = Creat(); }
	~BiTree() { Release(root); }
	void Search(char ch) { Search(root, ch); }
private:
	BiNode* Creat();
	void Release(BiNode* bt);
	void Search(BiNode* bt, char ch);
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
void BiTree::Search(BiNode* bt,char ch) {	
	if (bt->Lchild == NULL && bt->Rchild == NULL) { return ; }
	if(bt->Lchild!=NULL) {
		if (bt->Lchild->data == ch) { cout << bt->data; }
		else {
			Search(bt->Lchild, ch);
		}
	}
	if (bt->Rchild != NULL) {
		if (bt->Rchild->data == ch) { cout << bt->data; }
		else {
			Search(bt->Rchild, ch);
		}
	}
}
int main() {
	BiTree t;
	char ch=getchar();
	cin >> ch;
	t.Search(ch);
}