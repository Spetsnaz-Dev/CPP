#include <bits/stdc++.h>
#define base9 1e9
#define base7 1e7
#define ll long long int
#define ull unsigned long long int
#define pb push_back

using namespace std;

// solver functionzz
ll bi(string s){
    ll dec_value = 0; 
    int base = 1; 
  
    ll len = s.length(); 
    for (ll i = len - 1; i >= 0; i--) { 
        if (s[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
    return dec_value; 
}
ll solve(vector<ll> &v){
    ll n1 = 0, n2 = 0;
    for(auto x : v){
        n1 = max(n1, x);
        n2 = min(n2, x);
    }
    string binX = "", binY = "";
    while(n1){
        ll b = n1 & 1;
        binX += to_string(b);
        n1 >>= 1;
    }
    while(n2){
        ll b = n2 & 1;
        binY += to_string(b);
        n2 >>= 1;
    }
    string binXplusY = binX + binY;
    string binYplusX = binY + binX;

    ll XplusY = bi(binXplusY);
    ll YplusX = bi(binYplusX);

    return XplusY - YplusX;
}

int main()
{
    // Input
    ll t,n;
    cin>>t;
    while (t--){
        cin>>n;
        vector<ll> v(n);
        for(int i=0; i<n; i++)
            cin>>v[i];
        // Output
        cout<<solve(v)<<"\n";
    }
    return 0;
}
