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
void solve(int f, int s, int g, int u, int d){
    if(s == g){
        cout<<0;
        return;
    }

    queue<int> q;
    q.push(s);
    bool ok = false;
    int res = 1;
    while(!q.empty()){
        int size = q.size();
        while (size--)
        {
            int t = q.front();
            q.pop();

            if(t == g){
                ok = true;
                break;
            }

            int up = t + u;
            int down = t + d;
            if(up <= f)
                q.push(up);
            if(down <= f)
                q.push(down);
        }
        res++;
    }
    if(ok)
        cout<<res;
    else
        cout<<"use public transport";
}

int main()
{
    // Input
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    
    solve(f, s, g, u, d);
    cout<<"\n";
    return 0;
}
