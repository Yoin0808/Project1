#include  <iostream>
using  namespace  std;

const  int  MAXSIZE = 100;
template  <class  WeightType>
struct  EdgeType {
    int  from, to;
    WeightType  weight;
};


template  <class  DataType, class  WeightType>
class  EdgeGraph {
public:
    EdgeGraph(DataType  a[], int  n, int  e);
    ~EdgeGraph() {}
    WeightType  kruskal();
    int  findVertex(DataType  ver);    //查找某个顶点在顶点数组中的编号
    int  FindRoot(int  parent[], int  v);
    void  show();
private:
    int  vertexNum;
    int  edgeNum;
    DataType  vertex[MAXSIZE];
    EdgeType<WeightType>  edge[MAXSIZE];
};

template  <class  DataType, class  WeightType>
EdgeGraph<DataType, WeightType>::EdgeGraph(DataType  a[], int  n, int  e)
{
    vertexNum = n;
    edgeNum = e;
    for (int i = 0; i < n; ++i)
        vertex[i] = a[i];
    for (int k = 0; k < edgeNum; ++k) {
        DataType  m, n;
        WeightType  value;
        cin >> m >> n >> value;
        int i, j;
        i = findVertex(m);
        j = findVertex(n);
        edge[k].from = i;
        edge[k].to = j;
        edge[k].weight = value;
    }

    //按照边的权值大小排序
    for (int i = 0; i < edgeNum - 1; ++i)
        for (int j = 0; j < edgeNum - 1 - i; ++j)
            if (edge[j].weight > edge[j + 1].weight) {
                EdgeType<WeightType>  tmp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = tmp;
            }
}
template  <class  DataType, class  WeightType>
int  EdgeGraph<DataType, WeightType>::findVertex(DataType  ver)
{
    for (int i = 0; i < vertexNum; ++i)
        if (vertex[i] == ver)  return  i;
    return  -1;

}
template  <class  DataType, class  WeightType>
WeightType  EdgeGraph<DataType, WeightType>::kruskal()
{
    WeightType  minCost = 0;
    int num = 0, i, vex1, vex2;
    int parent[vertexNum];
    for (i = 0; i < vertexNum; i++) {
        parent[i] = -1;
    }
    for (num = 0, i = 0; num < vertexNum - 1; i++) {//num迭代
        vex1 = FindRoot(parent, edge[i].from);//返回from的根下标
        vex2 = FindRoot(parent, edge[i].to);//返回to的根下标
        if (vex1 != vex2) {
            minCost = minCost + edge[i].weight;
            parent[vex2] = vex1;//更新双亲结点
            num++;
        }
    }

    return  minCost;
}
template  <class  DataType, class  WeightType>
int  EdgeGraph<DataType, WeightType>::FindRoot(int  parent[], int  v) {
    int  t = v;
    while (parent[t] != -1) {
        t = parent[t];
    }
    return  t;
}
template  <class  DataType, class  WeightType>
void  EdgeGraph<DataType, WeightType>::show()
{
    for (int i = 0; i < edgeNum; ++i)
        cout << "(" << vertex[edge[i].from] << "," << vertex[edge[i].to] << ")  :" << edge[i].weight << endl;
}
int  main()
{
    int  n, e;
    cin >> n >> e;
    char  a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    EdgeGraph<char, int>  EG(a, n, e);
    //EG.show();
    cout << EG.kruskal() << endl;
    return  0;
}