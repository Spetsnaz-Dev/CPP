#include<iostream>
using namespace std;

int mergeArr(int arr[], int temp[], int left, int mid, int right) {
    int i= left;
    int j= mid;
    int k= left;
    
    int new_count=0;
    while(i<= mid-1 && j<= right) {
        if(arr[i]<= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            new_count+= (mid-i);
        }
    }
    while(i<=mid-1)
        temp[k++] = arr[i++];
    while(j<=right)
        temp[k++] = arr[j++];

    for(int i= left; i<=right; i++)
        arr[i] = temp[i];
        
    return new_count;
}


int mergeSorter(int arr[], int temp[], int low, int high) {
    int mid;
    int count=0;
    if(low<high) {
        mid= (low+high)/2;
        count= mergeSorter(arr, temp, low, mid);
        count+= mergeSorter(arr, temp, mid+1, high);
        count+= mergeArr(arr, temp, low, mid+1, high);
    }
    return count;
}

int findInversions(int arr[], int n) {
    int temp[n*2];
    return mergeSorter(arr, temp, 0, n-1);
}

int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        cout<<findInversions(arr, n) <<"\n";
    }
	return 0;
}