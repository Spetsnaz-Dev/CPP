// Method 1 --- DP
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = matrix.size();
        if(n == 0)
            return 0;
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        int maxlen = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    maxlen = max(maxlen, dp[i][j]);
                }
            }
        }
        return maxlen*maxlen;
    }
};


// METHOD 2 using DFS------TLE
// class Solution {
// public:
//     // Maximal Square
// bool isSafe(int i, int j, vector<vector<char>> grid){
//     if(i<0 or i >= grid.size() or j<0 or j >= grid[i].size())
//         return 0;
//     return 1;
// }
// int dfs(int i, int j, int count, vector<vector<char>> grid){
//     //check diagonal right is 1 or not
//     if(!isSafe(i+1, j+1, grid)){
//         return count*count;
//     }
//     //then check for max size of square formed
//     for(int k=0; k<=count; k++){
//         if(grid[i+1-k][j+1] == '0' or grid[i+1][j+1-k] == '0')
//             return count*count;
//     }

//     return dfs(i+1, j+1, count+1, grid);
// }
// int maximalSquare(vector<vector<char>>& grid) {
//     int n = grid.size();
//     if(n == 0)
//         return 0;
//     int m = grid[0].size();

//     int ans = 0;
//     for (size_t i = 0; i < n; i++)
//     {
//         for (size_t j = 0; j < m; j++)
//         {
//             if(grid[i][j] == '1')
//             {
//                 ans = max(ans, dfs(i, j, 1, grid));
//             }
//         }
//     }
//     return ans;
// }
// };