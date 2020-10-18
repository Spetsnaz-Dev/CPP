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

int main()
{
    // Input
    int t,row,col;
    cin>>t;
    while (t--){
        cin>>row>>col;
        bool ok = false;
        for(int i=0; i<row; i++){
            int a, b, c, d;
            cin>>a>>b>>c>>d;
            if(b == c)
                ok = true;
        }

        if(col % 2 == 0 and ok){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}
