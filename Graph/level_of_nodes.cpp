/*  Function to find level of node X
*   g[]: graph in input
*   n: number of vertices
*/
int bfs(int s, vector<int> g[], int n, int x, vector<int>& vis, vector<int>& level)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    level[0] = 0;
    
    if(q.front() == x)
        return level[0];
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        for(int i=0; i<g[curr].size(); i++)
        {
            if(vis[g[curr][i]] == false)
            {
                vis[g[curr][i]] = true;
                q.push(g[curr][i]);
                level[g[curr][i]] = level[curr] + 1;
                
                if(g[curr][i] == x)
                    return level[g[curr][i]];
            }
        }
    }
    return -1;
}
int levels(vector<int> g[], int n, int x)
{
    vector<int> vis(n), level(n);
    return bfs(0, g, n, x, vis, level);
}