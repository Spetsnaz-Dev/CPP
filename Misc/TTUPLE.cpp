#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
using namespace std;
ll a, b, c, x, y, z; 
static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
int findLowest(ll a, ll b, ll c){return min(a, min(b, c));}
bool check(ll a, ll b){return a==b;}
int chooseD(vector<int> &v){
    sort(v.begin(), v.end());
    int d;
    if(v[0] != 0)
        d = v[0];
    else if(v[1] != 0)
        d = v[1];
    else
        d = v[2];
    return d;
}
// solver functionzz
// (a,b,c) => (x,y,z)
int solve(ll a, ll b, ll c, ll x, ll y, ll z)
{
    if(a == x and b == y and c == z)
        return 0;

    ll counter = 0;
    vector<int> v;
    while(a != x or b != y or c != z)
    {
        v.clear();
        int xDiff = x - a, yDiff = y - b, zDiff = z - c;
        v.push_back(xDiff);v.push_back(yDiff);v.push_back(zDiff);
        int d = chooseD(v);

        if(a != x)
            a += d;
        if(b != y)
            b += d;
        if(c != z)
        c += d;
        counter++;
    }
    return counter;
}

int main()
{  
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    int t;
    cin>>t;
    while (t--){
        cin>>a>>b>>c;  cin>>x>>y>>z;
        // Output
        cout<<solve(a,b,c,x,y,z);

        cout<<"\n";
    }
    return 0;
}
