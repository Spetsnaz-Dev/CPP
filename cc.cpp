#include "bits/stdc++.h"
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
int solve(string s, int n, int k){
    // if(k >= n)
    //     return n;
    
    int maxx = 0;
    for(int i=0; i<n; i++){
        int c = 1;
        while(i+1 < n and s[i] == s[i+1]){
            c++;
            i++;
        }
        if(c > maxx){
            maxx = c;
        }
    }
    return min(n, maxx+k);
}

int main()
{
    // Input
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        cout<<solve(s, n, k);
        cout<<"\n";
    }
    return 0;
}
