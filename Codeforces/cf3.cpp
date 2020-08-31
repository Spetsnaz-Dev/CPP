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


string solve(string v, int x){
    string res(v.size(), '1');

    for(int i=0; i<v.size(); i++){
        if(v[i] == '0'){
            int l = i-x;
            int r = i+x;
            if(l>=0 and res[l] != '0')
                res[l] = '0';
            if(r < v.size() and res[r] != '0')
                res[r] = '0';
        }
    }
    // cout<<res<<" ";

    for(int i=0; i<v.size(); i++){
        if(v[i] == '1'){
            bool ok = false;
            int l = i-x;
            int r = i+x;
            if(l >= 0 and res[l] == '1'){
                res[l] = '1';
                ok = true;
            }
            if(r < v.size() and res[r] == '1'){
                res[r] = '1';
                ok = true;
            }
            if(!ok) return "-1";
        }
    }   
    return res;
}

int main()
{
    ll t,n;
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        int n;
        cin>>n;

        cout<<solve(s, n);
        cout<<"\n";
    }
    return 0;
}
