/*
=================================
Solved by Spetsnaz
=================================
*/
#include "bits/stdc++.h"
#define ll long long int
#define pb push_back
using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int findPosition(vector<int>& arr, int n, int p, int x){
    int minn = INT_MAX, pos = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == x and minn > abs(p - i)){
            minn = abs(p - i);
            pos = i;
        }
    }
    return pos;
}
// solver functionzz
int solve(vector<int>& arr, int n, int x, int p, int k){
    int count = 0;
    sort(arr.begin(), arr.end());

    int pos = findPosition(arr, n, p, x);
    if(arr[p-1] == x)
        return 0;
    
    if(arr[p-1] != x){
        arr[k-1] = x;
        count++;
        sort(arr.begin(), arr.end());

        if(arr[p-1] == x)
            return count;
    }

    if((p < k and arr[p-1] < x) or (p > k and arr[p-1] > x)){
        return -1;
    }

    pos = findPosition(arr, n, p, x) + 1;
    // we need these no of operations
    int res = abs(p - pos) + count;
    return res;
}

int main()
{
    // Input
    int t,n,x,p,k;
    cin>>t;
    while (t--){
        cin>>n>>x>>p>>k;
        vector<int> v(n);
        for (size_t i = 0; i < n; i++){cin>>v[i];}

        // Output
        cout<<solve(v, n, x, p, k);
        cout<<"\n";
    }
    return 0;
}
