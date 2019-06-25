//Max Subarray SUM excluding certain elements
#include<iostream>
using namespace std;

bool findElement(int key, int b[], int m) {
    for(int i=0;i<m;i++){
        if(b[i]== key)
            return true;
    }
    return false;
}

int max_Subarray_Sum(int arr[], int brr[], int n, int m) {
    int curr_sum=0, max_sum= -27184000;
    for(int i=0;i<n;i++) {
        if(findElement(arr[i], brr, m)) {
            curr_sum=0;
        }
        curr_sum= max(curr_sum+arr[i], arr[i]);
        max_sum= max(curr_sum, max_sum);
    }
    return max_sum;
}

int main() {
    int arr[] = { 3, 4, 5, -4, 6 }; 
    int brr[] = { 1, 8, 5 }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
    int m = sizeof(brr) / sizeof(brr[0]); 
    cout<<max_Subarray_Sum(arr, brr, n, m)<<"\n";

    return 0;
}