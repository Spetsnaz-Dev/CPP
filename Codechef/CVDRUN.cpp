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
string solve(int n, int k, int x, int y){
    if(x == y or k == 1)  return "YES";
    if(k == 0)  return "NO";
    
    set<int> st;
    int pos = x, prev_size = 0, new_size = 0;
    for(int t=1; t<=4; t++){
        for(int i=0; i<n; i++){
            st.insert(pos);
            pos = (pos + k) % n;
        }
        prev_size = new_size;
        new_size = st.size();
        if(prev_size == new_size)
            break;
    }
    if(st.find(y) == st.end())
        return "NO";
    return "YES";
}

int main()
{
    // Input
    ll t,n,k,x,y;
    cin>>t;
    while (t--){
        cin>>n>>k>>x>>y;
        // Output
        cout<<solve(n, k, x, y);
        cout<<"\n";
    }
    return 0;
}
