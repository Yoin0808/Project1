#define  Max  32767
#include<iostream>
#include<stdlib.h>
using  namespace  std;
template<class  DataType>
class  Hash {
public:
    Hash(DataType  a[], int  n, int  maxS, int  divi);
    ~Hash();
    int  H(DataType  key);//通过除留余数法计算哈希地址
    int  LineDetection(int  collision, DataType  value);
    void  SearchHash(DataType  key, int& cont);
private:
    DataType* arrPtr;
    int  maxSize, divisor;
};
template<class  DataType>
Hash<DataType>::Hash(DataType  a[], int  n, int  maxS, int  divi) {
    maxSize = maxS;
    divisor = divi;
    arrPtr = new  DataType[maxSize];
    for (int i = 0; i < maxSize; i++)
        arrPtr[i] = Max;
    for (int i = 0; i < n; i++) {
        int  hashLoc = H(a[i]);
        if (arrPtr[hashLoc] == Max)
            arrPtr[hashLoc] = a[i];
        else {
            int  newLoc = LineDetection(hashLoc, Max);
            if (newLoc != hashLoc)
                arrPtr[newLoc] = a[i];
            else  cout << "no  available  space" << endl;
        }
    }
}
template<class  DataType>
Hash<DataType>::~Hash() {
    arrPtr = NULL;
}
template<class  DataType>
int  Hash<DataType>::H(DataType  key) {
    return  key % divisor;
}
template<class  DataType>
int  Hash<DataType>::LineDetection(int  collision, DataType  value) {
    int  start = (collision + 1) % maxSize;//设置探测的起始下标
    while (start != collision) {
        if (arrPtr[start] == value || arrPtr[start] == Max)    break;
        else  start = (start + 1) % maxSize;//向后探测一个位置
    }
    return  start;
}
//cont记录带查找值所发生的关键码对比次数
template<class  DataType>
void  Hash<DataType>::SearchHash(DataType  key, int& cont) {
    cont = 0;
    int i,j;
    j = H(key);
    i = j;
    while (arrPtr[i]!=Max&&cont<maxSize) {//cont<maxSize防止死循环
        cont++;
        if (arrPtr[i] == key) { //arrPtr数组是散列表      
            break;
        }
        else {   
            i = (i + 1) % maxSize;
        }
    }
    /*for (int i = 0; i < maxSize; i++)
    {
        cout << arrPtr[i] << " ";
    }
    cout << endl;*/
}
int  main()
{
    int  maxS, divi;
    cin >> maxS >> divi;
    int  n;
    cin >> n;
    int  a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Hash<int>  hashTable(a, n, maxS, divi);
    int  key, cont = 0;
    cin >> key;
    hashTable.SearchHash(key, cont);
    cout << cont << endl;
    hashTable.~Hash();
    return  0;
}
