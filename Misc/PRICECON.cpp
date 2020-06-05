#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
// solver functionzz
void solve(vector<ll> v, ll k)
{
    ll res = 0;
    for(int x : v)
    {
        if(x > k)
        {
            res += x - k;
        }
    }
    cout<<res;
}

int main()
{  
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    int t;
    cin>>t;
    while (t--){
        ll n, k; cin>>n>>k;
        vector<ll> v(n);

        for(int i=0; i<n; i++)
            cin>>v[i];

        // Output
        solve(v, k);

        cout<<"\n";
    }
    return 0;
}
