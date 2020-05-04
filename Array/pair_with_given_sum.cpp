#include<bits/stdc++.h>
using namespace std;
int findPairs(int arr[], int n, int key)
{
    int count = 0;

    unordered_map<int, int> mp;
    for (size_t i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (size_t i = 0; i < n; i++)
    {
        if(mp.find(key - arr[i]) != mp.end())
            count += mp[key - arr[i]];
    }
    return count;
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