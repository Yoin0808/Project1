#include <iostream>
using namespace std;
struct BiNode {
	char data;
	BiNode* Lchild;
	BiNode* Rchild;
};
class BiTree {
public:
	BiNode* Root() {return root;}//返回值为根结点
	BiTree() {root = Create();}
	~BiTree() {Release(root);}
	void Release(BiNode* bt);
	void Del(char x) {Del(root, x);}
	void InOrder() {InOrder(root);}
private:
	BiNode* root;
	BiNode* Create();
	void Del(BiNode* bt, char x);
	void InOrder(BiNode* bt);
};

BiNode* BiTree::Create() {
	BiNode* bt;
	char a = getchar();
	if (a == '#')bt = NULL;
	else {
		bt = new BiNode;
		bt->data = a;
		bt->Lchild = Create();
		bt->Rchild = Create();
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

void BiTree::Del(BiNode* bt, char ch) {
	if (bt == NULL)return;
	else {
		if (bt->Lchild != NULL && bt->Lchild->data == ch) {
			bt->Lchild = NULL;
		}
		if ( bt->Rchild != NULL && bt->Rchild->data == ch) {
			bt->Rchild = NULL;
		}
		Del(bt->Lchild, ch);
		Del(bt->Rchild, ch);
	}
}

void BiTree::InOrder(BiNode* bt) {
	if (bt == NULL) {
		return;
	}
	else {
		InOrder(bt->Lchild);
		cout << bt->data << " ";
		InOrder(bt->Rchild);
	}
}

int main() {
	BiTree t;
	getchar();
	char ch ;
	cin >> ch;
	if (t.Root()->data == ch) {//判断根结点是否是被删除的
		cout << "Empty" << endl;
		return 0;
	}
	t.Del(ch);
	t.InOrder();
	return 0;
}