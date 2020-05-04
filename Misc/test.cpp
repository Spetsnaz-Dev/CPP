#include<bits/stdc++.h>
using namespace std;
int findPairs(int arr[], int n, int key)
{
    int count = 0, l = 0, r = n-1;
    sort(arr, arr+n);
    
    while(l < r)
    {
        int sum = arr[l]+arr[r];
        if(sum == key)
            count++;
        else if(sum > key)
            r--;
        else
            l++;
        r--;
    }
    return count > 0 ? count : -1;
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<findPairs(arr, n, k)<<"\n";
        }
	return 0;
}