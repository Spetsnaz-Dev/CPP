#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> res;
vector<int> v;
int solve(int n, int x){
    if(n <= 2)  return 1;

    int minn = 3, maxx = 3 + x - 1, res = 2;
    while (1)
    {   
        if(n >= minn and n <= maxx) 
            return res;

        minn = minn + x;
        maxx = minn + x - 1;
        // cout<<minn<<" - "<<maxx<<"\n";
        res++;
    }
    return res;
}
int main() 
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,x;
        cin>>n>>x;
        cout<<solve(n, x);
        cout<<endl;
    }
    return 0;
} 