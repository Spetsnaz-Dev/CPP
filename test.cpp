#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
#define ull unsigned long long int
#define pb push_back

using namespace std;


// solver functionzz
int solve(vector<ll>& arr, int n){
    
}

int main()
{  
    // Input
    ll t,n;
    cin>>t;
    while (t--){
        cin>>n;
        vector<ll> v(n);
        for (size_t i = 0; i < n; i++){cin>>v[i];}

        // Output
        cout<<solve(v, n);
        cout<<"\n";
    }
    return 0;
}
