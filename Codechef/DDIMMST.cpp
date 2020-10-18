#include "bits/stdc++.h"
#define ll long long int
#define ull unsigned long long int
#define pb push_back
using namespace std;

static int speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct triple
{
    int from, to, weight;
};

int selectMaxVertex(vector<int>& value, vector<bool>& setMST, int n){
    int minn = INT_MAX, vertex;
    for (int i = 0; i < n; i++)
    {
        if(setMST[i] == false and value[i] < minn)
        {
            vertex = i;
            minn = value[i];
        }
    }
    return vertex;
}
int makeMST(vector<vector<int>>& graph, int n){
    int parent[n];
    vector<int> value(n, INT_MIN);
    vector<bool> setMST(n, false);

    parent[0] = -1;
    value[0] = 0;

    for (int i = 0; i < n-1; i++)
    {
        int u = selectMaxVertex(value, setMST, n);
        setMST[u] = true;

        for (int j = 0; j < n; j++)
        {
            if(graph[u][j] != 0 and setMST[j] == false and graph[u][j] > value[j])
            {
                value[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }

    // print
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        res += graph[parent[i]][i];
    }
    return res;
}
int main()
{
    // Input
    int n, d;
    cin >> n >> d;
    vector<vector<int>> grid(n, vector<int>(d));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
            cin >> grid[i][j];
    }

    vector<triple> v;
    int c = -1;
    for (int i = 0; i < n; i++)
    {
        c++;
        for (int j = i + 1; j < n; j++)
        {
            for (int k = 0; k < d; k++)
            {
                int from = grid[j][k];
                int to = grid[i][c];
                int weight = abs(from - to);
                triple t;
                t.from = from;
                t.to = to;
                t.weight = weight;
                v.pb(t);
            }
        }
    }

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < v.size(); i++)
    {
        graph[v[i].from][v[i].to] = v[i].weight;
        graph[v[i].to][v[i].from] = v[i].weight;
    }
    // make MST
    int res = makeMST(graph, n);
    cout << res << "\n";
    return 0;
}
