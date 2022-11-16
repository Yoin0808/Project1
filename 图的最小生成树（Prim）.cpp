#include  <iostream>
#include  <string.h>
using  namespace  std;

const  int  MAXSIZE = 100;
const  int  MAXVALUE = 0x3f3f3f3f;
int  lowcost[MAXSIZE];    //存储最短边
int  adjvex[MAXSIZE];      //存储最短边的邻接顶点

template  <class  DataType, class  WeightType>
class  MGraph {
public:
    MGraph(DataType  a[], int  n, int  e);
    ~MGraph() {}
    WeightType  prim(int  v);
    int  findVertex(DataType  ver);    //查找某个顶点在顶点数组中的编号
    int  minEdge(WeightType  lowcost[], int  len);
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
        for (int j = 0; j < n; ++j) {
            edge[i][j] = MAXVALUE;      //求最小生成树时，需要对比交小值，所以这里初始化为无穷大
        }
    for (int i = 0; i < n; ++i)
        vertex[i] = a[i];
    for (int k = 0; k < e; ++k) {
        DataType  startVer, endVer;
        WeightType  weight;
        char m, n;
        int value;
        cin >> m >> n >> weight;
        int i, j;
        i = findVertex(m);
        j = findVertex(n);
        edge[i][j] = edge[j][i] = value;

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
WeightType  MGraph<DataType, WeightType>::prim(int  v)
{
    int  minCost = 0;
    int i, j, k;
    int adjvex[MAXSIZE], lowcost[MAXSIZE];
    for (i = 0; i < vertexNum; i++) {
        lowcost[i] = edge[v][i];//顶点v与各个顶点权值
        adjvex[i] = v;//表示候选最短边的邻接点
    } 
    lowcost[v] = 0;//lowcost值为0表示将对应顶点v加入集合U
    for (k = 1; k < vertexNum; k++) {//迭代n-1次
        j = minEdge(lowcost, vertexNum);
        minCost = minCost + lowcost[j];//每条边的最小权值
        lowcost[j] = 0;//j进入集合U后，需比较与其他的顶点的关系，进行更新
        for (i = 0; i < vertexNum; i++) {
            if (edge[i][j] < lowcost[i]) {
                lowcost[i] = edge[i][j];//更新最小值
                adjvex[i] = j;//更新邻接点
            }
        }
    }
    return  minCost;
}
template  <class  DataType, class  WeightType>
int  MGraph<DataType, WeightType>::minEdge(WeightType  lowcost[], int  len) {
    WeightType  minValue = MAXVALUE;
    int  minIndex = -1;
    for (int i = 0; i < len; ++i) {
        if (minValue > lowcost[i] && lowcost[i] != 0) {
            minValue = lowcost[i];
            minIndex = i;
        }
    }
    return  minIndex;
}
template  <class  DataType, class  WeightType>
void  MGraph<DataType, WeightType>::show()
{
    for (int i = 0; i < vertexNum; ++i) {
        for (int j = 0; j < vertexNum; ++j) {
            if (edge[i][j] == MAXVALUE)  cout << "∞" << "  ";
            else  cout << edge[i][j] << "  ";
        }
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
    char  startVer;
    cin >> startVer;
    //MG.show();
    cout << MG.prim(MG.findVertex(startVer)) << endl;
    return  0;
}