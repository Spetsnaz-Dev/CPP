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
int solve(int x1, int y1, int x2, int y2){
    if(x1 == x2 and y1 == y2)   return 0;

    int res = 1;
    queue<pair<int, int>> q;
    q.push({x1, y1});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int new_x, new_y;
        if(y + 2*x > 0){
            new_x = x;
            new_y = y + 2*x;
        }
        else if(y + 2*x < 0){
            new_x = -x;
            new_y = -(y + 2*x);
        }
        else if(y - 2*x > 0){
            new_x = x;
            new_y = y + 2*x;
        }
        else{
            new_x = -x;
            new_y = -(y - 2*x);
        }

        if(new_x == x2 and new_y == y2) return res;
        else    q.push({new_x, new_y});

        // new_x = x - 2*y, new_y = y;
        // if(new_x == x2 and new_y == y2) return res;
        // else    q.push({new_x, new_y});

        // // new_x = x + 2*y, new_y = y;
        // if(new_x == x2 and new_y == y2) return res;
        // else    q.push({new_x, new_y});

        // // new_x = x, new_y = y + 2*x;
        // if(new_x == x2 and new_y == y2) return res;
        // else    q.push({new_x, new_y});

        res++;
    }
    return res;
}

int main()
{
    // Input
    ll t,x1, y1, x2, y2;
    cin>>t;
    while (t--){
        cin>>x1>>y1>>x2>>y2;
        
        // Output
        cout<<solve(x1, y1, x2, y2);
        cout<<"\n";
    }
    return 0;
}
