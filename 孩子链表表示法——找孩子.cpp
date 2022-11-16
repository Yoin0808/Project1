#include<cstdlib>
#include<iostream>
using  namespace  std;
struct  CTNode {
    int  child;
    CTNode* next;
};
template<class  DataType>
struct  CBNode {
    DataType  data;
    CTNode* firstChild;
};
template<class  DataType>
class  ChildLink {
public:
    ChildLink(int  num);
    ~ChildLink();
    bool  findChild(DataType  elem, int  i, DataType& value);
    int  findPos(DataType  elem);
private:
    CBNode<DataType>* arrayPtr;
    int  nodeNUm;
};


template<class  DataType>
ChildLink<DataType>::ChildLink(int  num) {
    arrayPtr = new  CBNode<DataType>[num + 1];
    CTNode** arrayRear = new  CTNode * [num + 1];//尾插
    nodeNUm = num;
    for (int i = 1; i <= num; i++) {
        DataType  temp;
        cin >> temp;
        arrayPtr[i].data = temp;
        arrayPtr[i].firstChild = NULL;
    }
    int  row;
    cin >> row;
    for (int i = 0; i < row; i++) {
        DataType  parent, child;
        cin >> parent >> child;
        int  parLoc = findPos(parent);
        int  chiLoc = findPos(child);
        if (arrayPtr[parLoc].firstChild == NULL) {//第一个孩子
            arrayPtr[parLoc].firstChild = new  CTNode;
            arrayPtr[parLoc].firstChild->child = chiLoc;
            arrayPtr[parLoc].firstChild->next = NULL;
            arrayRear[parLoc] = arrayPtr[parLoc].firstChild;
        }
        else {
            CTNode* s = new  CTNode;//尾插
            s->child = chiLoc;
            s->next = NULL;
            arrayRear[parLoc]->next = s;
            arrayRear[parLoc] = s;
        }
    }
}

template<class  DataType>
ChildLink<DataType>::~ChildLink() {
    CTNode* first = NULL;
    for (int i = 1; i <= nodeNUm; i++) {
        first = arrayPtr[i].firstChild;
        while (first != NULL) {
            arrayPtr[i].firstChild = first->next;
            delete  first;
            first = arrayPtr[i].firstChild;
        }
    }
}
//查找元素elem的第i个孩子
template<class  DataType>
bool  ChildLink<DataType>::findChild(DataType  elem, int  i, DataType& value) {
    int a = findPos(elem); //找到elem在数组中的位置
    CTNode* first = arrayPtr[a].firstChild; //获得第一个孩子地址
    int count = 1;
    while (first && count < i) {
        first = first->next;
        count++;
    }
    if (first) { //表示存在第i个孩子
        value = arrayPtr[first->child].data; //引用变量赋值
        return true;
    }
    else
        return false;
}
template<class  DataType>
int  ChildLink<DataType>::findPos(DataType  elem) {
    for (int i = 1; i <= nodeNUm; i++)
        if (arrayPtr[i].data == elem)  return  i;
    return  0;//查找失败
}


int  main()
{
    int  n;
    cin >> n;
    ChildLink<char>  childLink(n);
    char  value, elem;
    int  i;
    cin >> elem;
    cin >> i;
    if (childLink.findChild(elem, i, value))
        cout << value << endl;
    else
        cout << "NO" << endl;
    childLink.~ChildLink();
    return  0;
}