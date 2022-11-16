#include  <iostream>
#include  <string.h>
using  namespace  std;

const  int  MAXSIZE = 100;
int  visited[MAXSIZE];
int  cont = 0;//记录一次深度优先遍历中图顶点的个数

template  <class  DataType, class  WeightType>
class  MGraph {
public:
    MGraph(DataType  a[], int  n, int  e);
    ~MGraph() {}
    void  DFT(int  v);
    int  findVertex(DataType  ver);    //查找某个顶点在顶点数组中的编号
    int  getVertexNum() { return  vertexNum; };
    void  show();
private:
    int  vertexNum;
    int  edgeNum;
    DataType  vertex[MAXSIZE];
    WeightType  edge[MAXSIZE][MAXSIZE];
};

template  <class  DataType, class  WeightType>
MGraph<DataType, WeightType>::MGraph(DataType  a[], int  n, int  e)
{
    vertexNum = n;
    edgeNum = e;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            edge[i][j] = 0;
    for (int i = 0; i < n; ++i)
        vertex[i] = a[i];
    for (int k = 0; k < e; ++k) {
        char m, n;
        int value;
        cin >> m >> n >> value;
        int i, j;
        i = findVertex(m);
        j = findVertex(n);
        edge[i][j] = value;
    }
}
template  <class  DataType, class  WeightType>
int  MGraph<DataType, WeightType>::findVertex(DataType  ver)
{
    for (int i = 0; i < vertexNum; ++i)
        if (vertex[i] == ver)  return  i;
    return  -1;
}
template  <class  DataType, class  WeightType>
void  MGraph<DataType, WeightType>::DFT(int  v)
{   
    visited[v] = 1;
    cont++;
    for (int i = 0; i < vertexNum; i++) {
        if (edge[v][i] != 0 && visited[i] == 0) DFT(i);
    }

}
template  <class  DataType, class  WeightType>
void  MGraph<DataType, WeightType>::show()
{
    for (int i = 0; i < vertexNum; ++i) {
        for (int j = 0; j < vertexNum; ++j)
            cout << edge[i][j] << "  ";
        cout << endl;
    }
}
int  main()
{
    int  n, e;
    cin >> n >> e;
    char  a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    MGraph<char, int>  MG(a, n, e);
    memset(visited, 0, n);
    MG.DFT(0);  //假设从0号顶点开始遍历
    if (cont == MG.getVertexNum())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return  0;
}