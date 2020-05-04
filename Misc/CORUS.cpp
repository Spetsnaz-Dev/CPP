#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
using namespace std;
int t, n, q, c;

// solver functionzz
int solve(string s, int c, unordered_map<char, int> mp){
    int n = s.size(), total = 0;

    for(auto x : mp)
    {
        int t = 0;
        while(x.second > 0 and t < c){
            x.second--, t++;
            total++;
        }
    }
    // mp.clear();
    return n-total;
}

int main()
{  
    // Input
    cin>>t;
    while (t--){
        // ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin>>n>>q;
        string s;
        cin>>s;

        int total = 0;
        unordered_map<char, int> mp;
    
        for (size_t i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        // Queries
        while (q--)
        {
            cin>>c;
        
            // Output
            cout<<solve(s, c, mp);
            cout<<"\n";
        }
    }
    return 0;
}