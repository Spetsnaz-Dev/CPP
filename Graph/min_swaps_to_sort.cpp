// https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/?ref=rp
#include "bits/stdc++.h"
using namespace std;

int minSwaps(int arr[], int n){
    int res = 0, i;
    
    pair<int, int> p[n];
    for(i=0; i<n; i++)
        p[i] = make_pair(arr[i], i);
        
    sort(p, p+n);   
    
    bool vis[n] = {0};
    
    for(i=0; i<n; i++){
        if(vis[i] or p[i].second == i)
            continue;
        else {
            int j = i, cycleSize = 0;
            
            while(!vis[j]){
                vis[j] = 1;
                j = p[j].second;
                cycleSize++;
            }
            if(cycleSize > 0)
                res += cycleSize - 1;
        }
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (size_t i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        cout<<minSwaps(arr, n)<<"\n";
    }
    return 0;
}