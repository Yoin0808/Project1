#include  <iostream>
#include  <string.h>
using  namespace  std;

const  int  MAXSIZE = 100;
int  visited[MAXSIZE];

template  <class  DataType, class  WeightType>
class  MGraph {
public:
    MGraph(DataType  a[], int  n, int  e);
    ~MGraph() {}
    void  BFT(int  v);
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
        edge[j][i] = value;//无向图
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
void  MGraph<DataType, WeightType>::BFT(int  v)
{
    int front, rear,m;
    front = rear = -1;
    int Q[MAXSIZE];
    cout << vertex[v];
    visited[v] = 1;
    Q[++rear] = v;
    while (front != rear) {
        m = Q[++front];
        for (int i = 0; i < vertexNum; i++) {
            if (edge[m][i] != 0 && visited[i] == 0) {
                cout << vertex[i];
                Q[++rear] = i; visited[i] = 1;
            }
        }
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
    char  a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    MGraph<char, int>  MG(a, n, e);
    memset(visited, 0, n);
    char  startVer;
    cin >> startVer;
    int  start = MG.findVertex(startVer);
    MG.BFT(start);
    for (int i = 0; i < MG.getVertexNum(); ++i) {
        if (visited[i] == 0)
            MG.BFT(i);
    }//若不是连通图，自动判断没有被访问的顶点，以此为顶点，继续遍历
    return  0;
}