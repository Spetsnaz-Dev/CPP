// Flood Fill
class Solution {
public:
    void dfs(vector<vector<int>>& img, int curr, int i, int j, int newColor)
    {   
        if(i<0 or i>=img.size() or j<0 or j>=img[i].size())
            return;
        if(img[i][j] != curr)
            return;
        
        img[i][j] = newColor;
        dfs(img, curr, i+1, j, newColor); //down
        dfs(img, curr, i-1, j, newColor); //up
        dfs(img, curr, i, j-1, newColor); //left
        dfs(img, curr, i, j+1, newColor); //right
    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int newColor) {
        int curr = img[sr][sc];
        
        if(curr == newColor)
            return img;
        dfs(img, curr, sr, sc, newColor);
        
        return img;
    }
};