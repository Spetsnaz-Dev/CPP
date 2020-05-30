static int speedUp = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
bool returnCyclic(int v, vector<bool>& vis, vector<bool>& recStack, vector<int> adj[])
{
    if(vis[v] == false)
    {
        vis[v] = true;
        recStack[v] = true;
        
        for(int i=0;i<adj[v].size();i++){
            if(!vis[adj[v][i]] && returnCyclic(adj[v][i], vis, recStack, adj))
                return true;
            else if(recStack[adj[v][i]])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> recStack(V);
    vector<bool> vis(V);
    
    for(int i=0;i<V;i++)
        if(returnCyclic(i, vis, recStack, adj))
            return true;
            
    return false;
}
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n = pre.size();
        
        vector<int> adj[numCourses];
        for(int i=0; i<n; i++)
        {
            int first = pre[i][0], second = pre[i][1];
            adj[first].push_back(second);
        }
        if(isCyclic(numCourses, adj))
            return false;
        else
            return true;
    }
};