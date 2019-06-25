//Find no of inversions in an array
#include<iostream>
using namespace std;

int mergeArr(int arr[], int temp[], int left, int mid, int right) {
    int i=left;    //for left Sub-Array
    int j=mid;    //for Right Sub-Array
    int k=left;    //for new array

    int new_count=0;
    while(i<=mid-1 && j<=right) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            new_count+= (mid-i);
        }
    }
    while(i<=mid-1)
        temp[k++]= arr[i++];

    while(j<=right)
        temp[k++] = arr[j++];
    
    for(int i=left; i<= right; i++)
        arr[i] = temp[i];

    return new_count;
}

int mergeSorter(int arr[], int temp[], int left, int right) {
    int mid, count=0;
    if(left< right) {
        mid= (left+right)/2;
        count= mergeSorter(arr, temp, left, mid);
        count+= mergeSorter(arr, temp, mid+1, right);
        count+= mergeArr(arr, temp, left, mid+1, right);
    }
    return count;
}

int findInversions(int arr[], int n) {
    int temp[n*2];
    return mergeSorter(arr, temp, 0, n-1);
}

int main() {
    int arr[]= {2, 4, 1, 3, 5};
    cout<<"No of inversions are - "<< findInversions(arr, 5) <<"\n";

    return 0;
}