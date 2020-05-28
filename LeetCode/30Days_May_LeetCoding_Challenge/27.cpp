static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
// Check if bipartite graph or check if graph has odd-cycle
class Solution {
public:
    bool isBipartite(vector<int> adj[], vector<int> &color, int node)
    {
        queue<int> q;
        q.push(node);
        color[node] = 1;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            for(int ele : adj[curr])
            {
                if(color[ele] == color[curr])
                    return false;
                else if(color[ele] == -1){
                    color[ele] = 1 - color[curr];
                    q.push(ele);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int n = dislikes.size();
        
//         make adjacancy list
        vector<int> adj[N+1];
        for(int i=0; i<n; i++)
        {
            int u = dislikes[i][0], v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
//         keep track of all colored edges
        vector<int> color(N+1, -1);
        for(int i=1; i<=N; i++)
        {
            if(color[i] == -1)
            {
                if(!isBipartite(adj, color, i))
                    return false;
            }
        }
        return true;
    }
};