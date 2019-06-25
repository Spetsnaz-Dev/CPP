#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
    int i, j, key;
    for(int i=0;i<n;i++) {
        key= arr[i];
        j=i-1;
        while(j>=0 && arr[j] > key ) {
            arr[j+1] = arr[j];
            j-=1;
        }
        arr[j+1]= key;
    }
}

void pendulumArrange(int arr[], int n) {
    int temp[n];
    InsertionSort(arr, n); 
    
    int k=0;
    int res= n%2== 0 ? 0 : 1;

    if(res==0) {
        for(int i= n-2; i>=0;i-=2) {
        temp[k++]= arr[i];
    }
    for(int j= 1; j < n; j+=2) {
        temp[k++]= arr[j];
    }
    for(int i= 0; i<n;i++)
        cout<<temp[i]<<" ";
    } 
    else 
    {
    for(int i= n-1; i>=0;i-=2) {
        temp[k++]= arr[i];
    }
    for(int i= 1; i < n; i+=2) {
        temp[k++]= arr[i];
    }
    for(int i= 0; i<n;i++)
        cout<<temp[i]<<" ";
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n= sizeof(arr)/sizeof(arr[0]);
    pendulumArrange(arr, n);

    return 0;
}