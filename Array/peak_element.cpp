#include<iostream>
using namespace std;

int binarySearch(int arr[], int low, int high) {
    int mid;
    while(low < high) {
        mid= (low+high)/2;
        if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1] )
            return mid;
        if(arr[mid] < arr[mid-1]) {
            high= mid-1;
            binarySearch(arr, low, high);
        }
        if(arr[mid] < arr[mid+1]) {
            low= mid+1;
            binarySearch(arr, low, high);
        }
    }
    return -1;
}

int peakElement(int arr[], int n) {
    return binarySearch(arr, 0, n-1);
}
int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n= sizeof(arr)/sizeof(arr[0]);

    cout<<peakElement(arr, n)<<"\n";

    return 0;
}