void dfs(vector<vector<char>>& grid, int i, int j) {
        
        if(i<0 or i>=grid.size())   return ;
        
        if(j<0 or j>=grid[i].size())    return ;
        
        // No need to check if already 0(water)
        if(grid[i][j] == '0')   return ;
        
        grid[i][j] = '0';
        
        dfs(grid, i-1, j);  //Up
        dfs(grid, i+1, j);  //Down
        dfs(grid, i, j+1);  //Right
        dfs(grid, i, j-1);  //Left
}
int numIslands(vector<vector<char>>& grid) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    int count = 0;
        
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            if(grid[i][j] == '1'){
                ++count;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}