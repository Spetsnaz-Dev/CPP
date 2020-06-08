#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll unsigned long long int
using namespace std;
ll t,ts;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

bool check(ll n, ll i)
{
    while(n and i and !(i & 1))
    {
        n >>= 1;
        i >>= 1;

        if(!(i & 1) and (n & 1))
            return 1;
    }
    return 0;
}
bool checkPowerOf2(ll x){return ((x != 0) && !(x & (x - 1)));}
// solver functionzz
ll solve(ll n)
{
    if(n & 1)
        return (n / 2);

    if(checkPowerOf2(n))
        return 0;
    
    ll res;
    while(!(n & 1))
    {
        n >>= 1;
    }

    res = n / 2;
    return res;
}

int main()
{  
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    // int t;
    cin>>t;
    while (t--){
        // string s;
        cin>>ts;

        // Output
        cout<<solve(ts);

        cout<<"\n";
    }
    return 0;
}
