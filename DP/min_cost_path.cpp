#include <bits/stdc++.h>
using namespace std;

int shortest(vector<vector<int> > grid ,int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int> > grid(n);

        for (int i = 0; i < n; i++) 
        {
            grid[i].resize(n);
            for (int j = 0; j < n; j++) 
            {
                cin >> grid[i][j];
            }
        }
        
        cout << shortest(grid,n) << endl;
    }
    return 0;
}
void isSafe(int i, int j, vector<vector<int> > grid, vector<int>& v, vector<vector<int>> dp){
    if(i>0)
        v.push_back(grid[i-1][j]);
    if(j>0)
        v.push_back(grid[i][j-1]);
    if(i<grid.size() and dp[i+1][j] != 0)
        v.push_back(grid[i+1][j]);
    if(j<grid[i].size())
        v.push_back(grid[i][j+1]);

    sort(v.begin(), v.end());
}
int shortest(vector<vector<int> > grid, int n) {
    
    vector<vector<int> > dp( n , vector<int> (n, 0));  
    dp[0][0] = grid[0][0];

    for (size_t i = 1; i < n; i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    
    for (size_t i = 1; i < n; i++)
        dp[0][i] = dp[0][i-1] + grid[0][i-1];

    for (size_t i = 1; i < n; i++)
        for (size_t j = 1; j < n; j++)
        {
            vector<int> vec;
            isSafe(i, j, grid, vec, dp);
            dp[i][j] = vec[0] + grid[i][j];
        }
    return dp[n-1][n-1];
}