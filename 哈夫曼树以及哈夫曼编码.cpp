#include<iostream>
#include<string.h>
using  namespace  std;
struct  HTNode {
    int  weight;
    int  parent, lchild, rchild;
};
class  HuffmanTree {
public:
    HuffmanTree(int  W[], int  n);
    ~HuffmanTree();
    void  Select(HTNode* HT, int  len, int& i1, int& i2);
    void  CreatHuffmanCode();
    void  showHuffmanCode(int  i);
private:
    int  nodeNum;
    HTNode* HT;//存储哈夫曼树
    char** HTC;//存储哈夫曼编码
};

HuffmanTree::HuffmanTree(int  W[], int  n) {
    nodeNum = n;
    HT = new  HTNode[2 * n - 1];
    //初始化
    for (int i = 0; i < 2 * nodeNum - 1; i++) {
        HT[i].lchild = -1;
        HT[i].rchild = -1;
        HT[i].parent = -1;
    }
    for (int i = 0; i < nodeNum; i++)
        HT[i].weight = W[i];
    //哈弗曼树构造
    for (int k = nodeNum; k < 2 * nodeNum - 1; k++) {
        int  i1, i2;
        Select(HT, k, i1, i2);
        HT[k].weight = HT[i1].weight + HT[i2].weight;
        HT[i1].parent = k;
        HT[i2].parent = k;
        HT[k].lchild = i1;
        HT[k].rchild = i2;
    }
}
HuffmanTree::~HuffmanTree() {
    HT = NULL;
    delete  HT;
    HTC = NULL;
    delete[]HTC;
}
void  HuffmanTree::Select(HTNode* HT, int  len, int& i1, int& i2) {
    int min1, min2;
    min1 = 9999;
    min2 = 9999;
    i1 = -1;//节点中最小权值的下标
    i2 = -1;//节点中倒数第二权值小的下标
    for (int i = 0; i < len; i++) {
        if (HT[i].parent != -1) continue;//该节点已经使用过
        if (HT[i].weight < min1) {
            min1 = HT[i].weight;
            i1 = i;
        }
    }
    for (int i = 0; i < len; i++) {
        if (HT[i].parent != -1) continue;//该节点已经使用过
        if (HT[i].weight < min2 && HT[i].weight > min1) {//保证比min1大
            min2 = HT[i].weight;
            i2 = i;
        }
    }
}
//进行赫夫曼编码                                                                                                //  CreatHuffmanTree
void  HuffmanTree::CreatHuffmanCode()
{
    //从叶子到根逆向求每个字符的赫夫曼编码，存储在编码表HC中
    int  i, start, c, f;
    HTC = new  char* [nodeNum];                                                                  //分配n个字符编码的头指针矢量
    char* cd = new  char[nodeNum];                                                        //分配临时存放编码的动态数组空间
    cd[nodeNum - 1] = '\0';                                                                        //编码结束符
    for (i = 0; i < nodeNum; ++i)
    {                                                                                                    //逐个字符求赫夫曼编码
        start = nodeNum - 1;                                                                    //start开始时指向最后，即编码结束符位置
        c = i;
        f = HT[i].parent;                                                          //f指向结点c的双亲结点
        while (f != -1)
        {                                                                                            //从叶子结点开始向上回溯，直到根结点
            --start;                                                                    //回溯一次start向前指一个位置
            if (HT[f].lchild == c)
                cd[start] = '0';                                                //结点c是f的左孩子，则生成代码0
            else
                cd[start] = '1';                                                  //结点c是f的右孩子，则生成代码1
            c = f;
            f = HT[f].parent;                                                  //继续向上回溯
        }                                                                                            //求出第i个字符的编码
        HTC[i] = new  char[nodeNum - start];                                          //  为第i  个字符编码分配空间
        strcpy(HTC[i], &cd[start]);                                        //将求得的编码从临时空间cd复制到HC的当前行中
    }
    delete  cd;                                                                                //释放临时空间
}
void  HuffmanTree::showHuffmanCode(int  i)
{
    cout << HTC[i - 1] << endl;
}
int  main()
{
    int  n;
    cin >> n;
    int  W[n];
    for (int i = 0; i < n; i++)
        cin >> W[i];
    HuffmanTree  huffmanTree(W, n);
    huffmanTree.CreatHuffmanCode();
    int  i;
    cin >> i;
    if (i<1 || i>  n)
        cout << "NO" << endl;
    else
        huffmanTree.showHuffmanCode(i);
    huffmanTree.~HuffmanTree();
    return  0;
}