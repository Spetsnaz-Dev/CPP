class Solution {
public:
    bool isCyclic(vector<int> adj[], vector<int> vis, int curr)
    {
        if(vis[curr] == 2)
            return true;
        
        vis[curr] = 1;
        
        bool flag = 0;
        for(int i=0; i<adj[curr].size(); i++)
        {
            if(vis[adj[curr][i]] == 1)
                vis[adj[curr][i]] = 2;
            else
            {
                flag = isCyclic(adj, vis, adj[curr][i]);
                if(flag)
                    return true;
            }
        }
        return false;
    }
    bool possibleBipartition(int n, vector<vector<int>>& v) {
        
        if(n <= 2)
            return true;
        
        //make adj list
        vector<int> adj[n+1];
        for(int i=0; i<v.size(); i++)
        {
            int a = v[i][0], b = v[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int> vis(n+1);
        for(int i=1; i<=n; i++)
        {
            vis[i] = 1;
            for(int j=0; j<adj[i].size(); j++)
            {
                //if cycle found then we return false
                if(isCyclic(adj, vis, adj[i][j]))
                    return false;
            }
            vis[i] = 0;
        }
        return true;
    }
};