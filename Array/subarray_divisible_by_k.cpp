//Longest subarray with sum divisible by K
#include<bits/stdc++.h>
using  namespace std;
void subarrayDivisiblebyK(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int aux[n];
    int res_len=0;
    int sum = 0;

    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        aux[i] = ((sum % k) + k) % k;
        //cout<<aux[i]<<" ";
    }
    for(int i=0;i<n;i++)
    {
        if(aux[i] == 0)
            res_len = i+1;
        else if(mp.find(aux[i]) == mp.end())
        {
            mp[aux[i]] = i;
        }
        else
        {
            if(res_len < i - mp[aux[i]])
                res_len = i - mp[aux[i]];
        }
    }
    cout<<res_len<<"\n";
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        subarrayDivisiblebyK(arr, n, k);
    }
}