#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int l, int h, int x) 
{ 
    while (l <= h) 
    { 
        int mid = (l+h) / 2; 
  
        // if 'x' is greater than or equal to arr[mid],  
        // then search in arr[mid+1...h] 
        if (arr[mid] <= x) 
            l = mid + 1; 
  
        // else search in arr[l...mid-1]     
        else
            h = mid - 1;     
    }
    // required index 
    return h; 
} 

int countElements(int arr[], int brr[], int n, int query) {
    int x= arr[query];
    int count=0;
    // for(int i=0;i<n;i++) {
    //     if(brr[i] <= x)
    //         count++;
    // }
    return partition(brr, x);
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n], brr[n], i;
        for(i=0;i<n;i++)
            cin>>arr[i];
        for(i=0;i<n;i++)
            cin>>brr[i];
        int q;
        cin>>q;
        while(q--) {
            int query;
            cin>>query;
            cout<<countElements(arr, brr, n, query)<<"\n";
        }
    }
	return 0;
}