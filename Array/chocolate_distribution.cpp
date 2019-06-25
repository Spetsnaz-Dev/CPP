
//Chocolate Distribution Problem
#include<bits/stdc++.h>
using namespace std;
//Sort
int Partition(int arr[], int low, int r) {
    int x= arr[r];
    int i= low-1;
    for(int j=low; j<r; j++) {
        if(arr[j] <= x) {
            i+=1;
            int temp= arr[i];
            arr[i]= arr[j];
            arr[j]= temp;
        }
    }
    int temp= arr[i+1];
    arr[i+1]= arr[r];
    arr[r]= temp;
    return i+1;
}

void qSort(int arr[], int p, int r) {
    if(p<r) {
        int q= Partition(arr, p, r);
        qSort(arr, p, q-1);
        qSort(arr, q+1, r);
    }
}
//Sort End
int chocoDistribute(int arr[], int n, int m) {
    if(n==0 || m==0 || n<m)
        return -1;

    qSort(arr, 0, n-1);     //Sort the array

    int min_diff= INT_MAX;
    for(int i=0; i+m-1<n; i++) {
        int curr_diff= arr[i+m-1] - arr[i];
        if(curr_diff < min_diff) {
            min_diff= curr_diff;
        }
    }
    return min_diff;
}

int main() {
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 
                 30, 40, 28, 42, 30, 44, 48, 
                 43, 50};
    int m=7;
    int n= sizeof(arr)/sizeof(arr[0]);

    int res= chocoDistribute(arr, n, m);
    cout<<res<<" \n";

    return 0;
}