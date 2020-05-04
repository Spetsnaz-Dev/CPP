#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll unsigned long long int
using namespace std;

// solver function
ll solve(ll x){

    if(x == 0)
        return 0;

    vector<int> v;
    for(int i=0; i<32; i++)
        v.push_back(0);

    int i = 31;
    while(x){
        v[i] = x & 1;
        i--;
        x >>= 1;
    }
    reverse(v.begin(), v.end());

    ll dec = 0, base = 1;
    for(int i=31; i>=0; i--){
        dec += base * v[i];
        base = base * 2;
    }
    
    return dec;
}

int main()
{  
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> res;
    res.clear();

    // Input
    ll x;
    while(cin>>x){
        ll ele = solve(x);
        res.push_back(ele);
    }

    for(auto i=0; i < res.size()-1; i++)
        cout<<res[i]<<", ";
    cout<<res[res.size()-1]<<"\n";
}