#include  <iostream>
using  namespace  std;
void  split(int  A[], int  n) {

    int temp;
    int i=0, j=n-1;
    while (i < j) {       
        while (i < j && A[i] % 2 != 0) i++;
        while (i < j && A[j] % 2 == 0) j--;
        if (i<j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
}
void  show(int  A[], int  n) {
    for (int i = 0; i < n; ++i)
        cout << A[i] << "  ";
    cout << endl;
}
int  main()
{
    int  n;
    cin >> n;
    int  a[100];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    split(a, n);
    show(a, n);
    return  0;
}
