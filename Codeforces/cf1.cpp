#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
#define ull unsigned long long int
#define pb push_back

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


void solve(vector<int>& arr, int n){
    if(n <= 2){  
        cout<<"-1"; 
        return;
        }

    if(arr[0]+arr[1] > arr[n-1]){
        cout<<"-1";
        return;
    }
    cout<<"1 "<<"2 "<<n;
    return;
}

int main()
{
    ll t,n;
    cin>>t;
    while (t--){
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++)  cin>>v[i];
        solve(v, n);
        cout<<"\n";
    }
    return 0;
}