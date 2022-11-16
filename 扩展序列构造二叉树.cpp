#include<stack>
#include  <cstdlib>
#include<iostream>
using  namespace  std;
template<class  DataType>
struct  BiNode {
    DataType  data;
    BiNode<DataType>* lchild, * rchild;
};
template<class  DataType>
class  BiTree {
public:
    BiTree() { root = PreCreate(root); };
    ~BiTree() { Release(root); };
    void  InOrder() { InOrder(root); };
private:
    BiNode<DataType>* root;
    BiNode<DataType>* PreCreate(BiNode<DataType>* bt);
    void  Release(BiNode<DataType>* bt);    //∫Û–Ú Õ∑≈
    void  InOrder(BiNode<DataType>* bt);
};

template<class  DataType>
BiNode<DataType>* BiTree<DataType>::PreCreate(BiNode<DataType>* bt) {
    char ch;
    cin >> ch;
    if (ch == '#') bt = nullptr;
    else {
        bt = new BiNode<DataType>;
        bt->data = ch;
        bt->lchild=PreCreate(bt->lchild);
        bt->rchild=PreCreate(bt->rchild);
    }
    return bt;

}
template<class  DataType>
void  BiTree<DataType>::Release(BiNode<DataType>* bt) {
    if (bt == NULL)  return;
    else {
        Release(bt->lchild);
        Release(bt->rchild);
        bt = NULL;
        delete  bt;
    }
}
template<class  DataType>
void  BiTree<DataType>::InOrder(BiNode<DataType>* bt) {
    if (bt == NULL) return ;
    else {
        InOrder(bt->lchild);
        cout << bt->data;
        InOrder(bt->rchild);
    }

}

int  main()
{
    BiTree<char>  biTree;
    biTree.InOrder();
    biTree.~BiTree();
    return  0;
}