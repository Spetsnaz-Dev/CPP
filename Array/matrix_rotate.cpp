#include<iostream>
#define N 50
using namespace std;
void swap(int a, int b) {
    int temp = a;
    a=b;
    b=temp;
}
void swap(int a, int b) {
    int temp = a;
    a=b;
    b=temp;
}
void swapColumns(int a[][N], int n) {
    int k=n-1;
    for(int i=0;i<n;i++)
        for(int j=0; j<n && j<k; j++;k--)
        {
            swap(a[i][j], a[k][i]);
        }
}
void transpose(int a[][N], int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            swap(a[i][j], a[j][i]);
}
void rotateby90(int n, int a[][N]){
    transpose(a, n);
    swapColumns(a, n);
}
int main()
{
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];
    rotateby90(n, arr);

    return 0;
}