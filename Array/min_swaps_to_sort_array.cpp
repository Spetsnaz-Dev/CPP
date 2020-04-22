// https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/?ref=rp
#include "bits/stdc++.h"
using namespace std;

int minSwaps(int arr[], int n){
    int res = 0, i;
    
    pair<int, int> p[n];
    for(i=0; i<n; i++)
        p[i] = make_pair(arr[i], i);
        
    sort(p, p+n);   
    
    i=0;
    while(i < n)
    {
        if(p[i].second == i){
            i++;
            continue;
        }
        else {
            while(p[i].second != i){
                swap(p[i].first, p[p[i].second].first);
                swap(p[i].second, p[p[i].second].second);
                res++;
            }
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