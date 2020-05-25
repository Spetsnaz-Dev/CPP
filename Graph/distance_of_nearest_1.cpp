#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &arr, int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
    }
    cout << "\n";
}

void nearest(vector<vector<int>> arr, int r, int c) {
    vector<pair<int, int>> v;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(arr[i][j] == 1)
                v.push_back({i, j});
               
    vector<int> res; 
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(arr[i][j] == 0)
            {
                int ans = INT_MAX;
                for(auto x=0; x<v.size(); x++)
                {
                    int dist = abs(v[x].first - i) + abs(v[x].second - j);
                    ans = min(ans, dist);
                    if(dist > ans)
                        break;
                }
                res.push_back(ans);
            }
            else
                res.push_back(0);
        }
    }
    for(auto x : res)
        cout<<x<<" ";
}
int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int row, col;
        cin >> row >> col;

        // Input matrix is represented using vectors of vectors
        vector<vector<int>> graph(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> graph[i][j];
            }
        }

        nearest(graph, row, col);
    }

    return 0;
}