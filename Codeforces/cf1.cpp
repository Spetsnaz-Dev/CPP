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


ll solve(ll x, ll y, ll k){

    ll rem = (y * k + k - 1);
    if(rem % (x-1) != 0)
        rem += rem/(x-1) + 1;
    rem += k;
    return rem;
}

int main()
{
    ll t,x,y,z;
    cin>>t;
    while (t--){
        cin>>x>>y>>z;
        cout<<solve(x, y, z);
        cout<<"\n";
    }
    return 0;
}