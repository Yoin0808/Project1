#include  <iostream>
#include  <string.h>
using  namespace  std;

const  int  MAXSIZE = 100;
const  int  MAXVALUE = 0x3f3f3f3f;
int  lowcost[MAXSIZE];    //�洢��̱�
int  adjvex[MAXSIZE];      //�洢��̱ߵ��ڽӶ���

template  <class  DataType, class  WeightType>
class  MGraph {
public:
    MGraph(DataType  a[], int  n, int  e);
    ~MGraph() {}
    WeightType  prim(int  v);
    int  findVertex(DataType  ver);    //����ĳ�������ڶ��������еı��
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
            edge[i][j] = MAXVALUE;      //����С������ʱ����Ҫ�ԱȽ�Сֵ�����������ʼ��Ϊ�����
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
        lowcost[i] = edge[v][i];//����v���������Ȩֵ
        adjvex[i] = v;//��ʾ��ѡ��̱ߵ��ڽӵ�
    } 
    lowcost[v] = 0;//lowcostֵΪ0��ʾ����Ӧ����v���뼯��U
    for (k = 1; k < vertexNum; k++) {//����n-1��
        j = minEdge(lowcost, vertexNum);
        minCost = minCost + lowcost[j];//ÿ���ߵ���СȨֵ
        lowcost[j] = 0;//j���뼯��U����Ƚ��������Ķ���Ĺ�ϵ�����и���
        for (i = 0; i < vertexNum; i++) {
            if (edge[i][j] < lowcost[i]) {
                lowcost[i] = edge[i][j];//������Сֵ
                adjvex[i] = j;//�����ڽӵ�
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
            if (edge[i][j] == MAXVALUE)  cout << "��" << "  ";
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