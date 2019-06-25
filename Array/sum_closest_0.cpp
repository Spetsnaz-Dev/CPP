// Two elements whose sum is closest to zero
#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r) {
    int x= arr[r];
    int i=l-1;
    int j;
    for(j=l; j<r-1; j++) {
        if(arr[j] <= x) {
            i+=1;
            int temp= arr[i];
            arr[i]= arr[j];
            arr[j]= temp;
        }
    }
    i+=1;
    int temp= arr[i];
    arr[i] = arr[r];
    arr[r]= temp;

    return i+1;
}

void quickSort(int arr[], int p, int r) {
    int piv;
    if(p<r) {
        piv= partition(arr, p, r);
        quickSort(arr, 0, piv-1);
        quickSort(arr, piv+1, r);
    }
}

void minSum(int arr[], int n) {
    int l=0, r= n-1;
    quickSort(arr, l, r);

    int min_sum= INT_MAX;
    int min_l= l;
    int min_r= r;
    while(l<r) {
        int curr_sum= arr[l]+ arr[r];
        if(abs(curr_sum) <= abs(min_sum)) {
            min_sum= curr_sum;
            min_l= l;
            min_r= r;
        }
        if(curr_sum<0)
            l++;
        else
            r--;
    }
    cout<<"Closest sum elements are "<<arr[min_l]<<" and "<<arr[min_r]<<"\n";
}

int main() {
    int arr[] = { 1, 60, -10, 70, -80, 85 };
    int n = sizeof(arr)/sizeof(arr[0]); 
    minSum(arr, n);

    return 0;
}