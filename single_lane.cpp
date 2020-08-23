#include<bits/stdc++.h>
#define ll size_t
#define pb push_back
#define mod 1000000007
using namespace std;

This is a group theory problem. We find number of all possible cycles in all possible permutations in S_n. So number of permutations is always n!. Now let say our cycle type in a particular permutation is 1(C1), 2(C2),...n(Cn). Where Ci is the number of cycles of length i. We find the number of permutations of this cycle type that is \frac{n!}{C1! C2! ... Cn! 1^(C1) 2^(C2)...n^(Cn) }. Now we have to consider all possible cycle types. Also we have a constraint that \sum_{i=1}^{n} i(Ci) = n (condition *)
So given n we fix n variables C1, C2, ... Cn
For 1 \leq i \leq n
For 0 \leq Ci \leq n/i and condition *
Compute k = \frac{n!}{C1! C2! ... Cn! 1^(C1) 2^(C2)...n^(Cn) }
Now sum = 0
sum = sum + k
Result = sum/n!
ll groupCount(vector<ll>& arr)
{
    ll c = 0, minn = LONG_MAX;
    for(ll i=0;i<arr.size();i++){
        if(arr[i]<minn){
            c = (c + 1) % mod;
            minn = arr[i];
        }
    }
    return c;
}

void generate(vector<ll> &arr, ll &groups, ll &perm_count, ll l, ll r)
{
    if(l == r)
    {
        groups = (groups + (groupCount(arr) % mod) % mod);
        perm_count = (perm_count + 1) % mod;
        return;
    }

    // similar to string permutation 
    for(auto i = l; i <= r; i++)
    {
        swap(arr[l], arr[i]);
        generate(arr, groups, perm_count, l+1, r);
        swap(arr[l], arr[i]);
    }
    return;
}

double solve(vector<ll>& arr, int n){

    ll group_count=0,perm_count=0; 
    generate(arr, group_count,perm_count, 0, n-1);

    double res = (double) group_count / perm_count;
    return res;
}

int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);

    for(ll i = 0; i < n; i++)
        cin>>arr[i];
    
    // print final result as double
    // cout<<res;
    printf("%0.6lf", solve(arr, n));

    return 0;
}