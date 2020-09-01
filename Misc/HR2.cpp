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
string solve(string s, int k)
{
    int n = s.size(), i = 0;
    string res = "";
    while(i < n){
        if(k>0){
            if(s[i] == '0'){
                res += '1';
                k--;
            }
            else
                res += '0';
        }
        else
            res += '0';
        i++;
    }
    return res;
}
int main()
{
    // Input
    int t,k;
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        cin>>k;

        // Output
        cout<<solve(s, k);
        cout<<"\n";
    }
    return 0;
}
