#include<bits/stdc++.h>
using namespace std;
//Method 1- ----- Use Randomized QuickSelect

// Standard partition process of QuickSort().  It considers the last 
// element as pivot and moves all smaller element to left of it and 
// greater elements to right. This function is used by randomPartition() 
int partition(int arr[], int l, int r) 
{ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(arr[i], arr[j]); 
            i++; 
        } 
    } 
    swap(arr[i], arr[r]); 
    return i; 
} 
  
// Picks a random pivot element between l and r and partitions 
// arr[l..r] around the randomly picked element using partition() 
int randomPartition(int arr[], int l, int r) 
{ 
    int n = r-l+1; 
    int pivot = rand() % n; 
    swap(arr[l + pivot], arr[r]); 
    return partition(arr, l, r); 
} 
int kthSmallest(int arr[], int l, int r, int k) 
{ 
    // If k is smaller than number of elements in array 
    if (k > 0 && k <= r - l + 1) 
    { 
        // Partition the array around a random element and 
        // get position of pivot element in sorted array 
        int pos = randomPartition(arr, l, r); 
  
        // If position is same as k 
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  // If position is more, recur for left subarray 
            return kthSmallest(arr, l, pos-1, k); 
  
        // Else recur for right subarray 
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
  
    // If k is more than the number of elements in the array 
    return INT_MAX; 
} 
//Method 2 ----- Use normal QuickSelect
// int partition(int arr[], int l, int r) 
// { 
//     int x = arr[r], i = l; 
//     for (int j = l; j <= r - 1; j++) { 
//         if (arr[j] <= x) { 
//             swap(arr[i], arr[j]); 
//             i++; 
//         } 
//     } 
//     swap(arr[i], arr[r]); 
//     return i; 
// } 
// int kthSmallest(int arr[], int l, int r, int k) 
// { 
//     // If k is smaller than number of  
//     // elements in array 
//     if (k > 0 && k <= r - l + 1) { 
//         int index = partition(arr, l, r); 
  
//         if (index - l == k - 1) 
//             return arr[index]; 

//         if (index - l > k - 1)  
//             return kthSmallest(arr, l, index - 1, k); 
  
//         return kthSmallest(arr, index + 1, r,  
//                             k - index + l - 1); 
//     } 
//     // If k is more than number of  
//     // elements in array 
//     return INT_MAX; 
// } 
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
        int k;
        cin>>k;
        int res = kthSmallest(arr, 0, n-1, k);
        //cout<<quickSelect(arr, 0, n-1, k)<<"\n";
        cout<<res<<"\n";
        }
	return 0;
}