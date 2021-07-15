// Leetcode 797
void dfs(int src, int dest, vector<vector<int>>& graph, vector<vector<int>>& res, vector<int> path) {
    path.push_back(src);
    
    if(src == dest) {
        res.push_back(path);
        return;
    }
    
    for(int i : graph[src]) {
        dfs(i, dest, graph, res, path);
    }
    path.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> res;
    vector<int> path;
    
    dfs(0, n-1, graph, res, path);
    return res;
}