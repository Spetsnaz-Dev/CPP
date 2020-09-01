#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
#define ull unsigned long long int
#define pb push_back

using namespace std;
// Fast I/O
static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// solver
ll solve(string s)
{
    ll res = 0, curr, n = s.size();
    bool ok;
    for(ll init=0; init <= INT_MAX and ok!= true; init++)
    {
        curr = init;
        ok = true;
        for(int i=0; i<n; i++)
        {
            res += 1;
            while(i < n and s[i++] == '-'){
                curr -= 1;
                if(curr < 0)
                    break;
            }
            while(i < n and s[i++] == '+')
                curr += 1;
        }
    }
    return res;
}
int main()
{
    // Input
    int t;
    cin>>t;
    string s;
    while (t--){
        cin>>s;
        // Output
        cout<<solve(s);
        cout<<"\n";
    }
    return 0;
}
