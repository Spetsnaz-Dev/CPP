#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
#define ull unsigned long long int
#define pb push_back

using namespace std;
int t,n,k,l;
// solver functionzz
void solve(){

    if(k*l < n or (k == 1 and n != 1)) {cout<<"-1"; return;}

    vector<int> count(k, l), res(n, 0);
    
    int x = 0, i = 0;
    for(int x=0; x<n; x++){
        while(1){
            if(count[i] > 0){
                // if(res[x] == 0){
                    res[x++] = i+1;
                    count[i]--;
                // }
                // count[i]--;
            }
            i = (i+1) % k;
            if(x >= n)  break;
        }
    }
    for(int i : res)
        cout<<i<<" ";
}

int main()
{
    // Input
    cin>>t;
    while (t--){
        cin>>n>>k>>l;
        solve();
        cout<<"\n";
    }
    return 0;
}
