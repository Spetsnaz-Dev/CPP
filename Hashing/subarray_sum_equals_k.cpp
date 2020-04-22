#include "bits/stdc++.h"
using namespace std;
int subarraySum(vector<int> arr, int k)
{
    int n = arr.size();

    if(n == 0)
        return 0;
    
    unordered_map<int, int> mp;
    int curr = 0, res = 0;
    for (size_t i = 0; i < n; i++)
    {
        curr += arr[i];

        if(curr == k)
            res ++;

        if(mp.find(curr - k) != mp.end())
            res += mp[curr - k];
        
        mp[curr]++;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    int k;

    for (size_t i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    cin>>k;

    cout<<subarraySum(v, k)<<"\n";

    return 0;
}