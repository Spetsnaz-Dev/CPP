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
// solver functionzz
int solve(){}

int main()
{  
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    ll t,n;
    cin>>t;
    while (t--){
        cin>>n;
        vector<ll> v(n);
        for (size_t i = 0; i < n; i++){cin>>v[i];}

        // Output
        cout<<solve();
        cout<<"\n";
    }
    return 0;
}
