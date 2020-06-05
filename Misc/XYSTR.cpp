#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
using namespace std;
int t;
string s;
static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
// solver functionzz
int solve(string s)
{
    int c = 0;
    for(int i=1; i<s.size(); i++)
    {
        char a = s[i-1], b = s[i];
        if(a == b)
            continue;
        c++;
        i++;
    }
    return c;
}

int main()
{  
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    // int t;
    cin>>t;
    while (t--){
        // string s;
        cin>>s;

        // Output
        cout<<solve(s);

        cout<<"\n";
    }
    return 0;
}
