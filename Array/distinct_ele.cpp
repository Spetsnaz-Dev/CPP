//Count no of distinct elements in every window of size K
#include<bits/stdc++.h>
using namespace std;

void countDistinct(int arr[], int n, int k) {
    map<int, int> h;
    int i, d_Count=0;
    for(i=0;i<k;i++) {
        if(h[arr[i]] == 0)
            d_Count++;
        h[arr[i]]++;
    }
    cout<<d_Count<<"\n";

    for(i=k;i<n;i++) {
        if(h[arr[i-k]] == 1)
            d_Count--;
        h[arr[i-k]]--;

    if(h[arr[i]] == 0)
        d_Count++;
        h[arr[i]]++;

    cout<<d_Count<<"\n";
    }
}

int main() {
    int arr[] = { 1, 2, 1, 3, 4, 2, 3 };
    int size = sizeof(arr)/sizeof(arr[0]); 
    int k=4;
    countDistinct(arr, size, k);

    return 0;
}