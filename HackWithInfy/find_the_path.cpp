#include <bits/stdc++.h>
using namespace std;
#define int long long
const int nax = 1e5;
vector<int> adj[nax];
vector<int> x;
int cnt = 0;
int dfs(int i)
{
    for (auto y : adj[i])
    {
        if (y == i + 1 && x[y] > x[i])
        {
            cnt++;
            dfs(y);
        }
    }
    return cnt + 1;
}

int longest(vector<int> a, vector<int> b)
{
    int sz = a.size();
    for (int i = 0; i < sz; i++)
    {
        int u = a[i];
        int v = b[i];

        adj[u].push_back(v);
    }
    int ans = 0;

    for (int i = 0; i < x.size(); i++)
    {
        cnt = 0;
        ans = max(ans, dfs(i));
    }
    return ans;
}

#undef int
int main()
{
#define int long long
    int n, val;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> val;
        x.push_back(val);
    }
    int m;
    cin >> m;
    vector<int> a;
    vector<int> b;
    for (int i = 1; i <= m; i++)
    {
        cin >> val;
        a.push_back(val - 1);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> val;
        b.push_back(val - 1);
    }
    cout << longest(a, b) << endl;
}