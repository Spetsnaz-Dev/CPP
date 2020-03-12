/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/

//  Method 1
bool isCyclic_util(vector<int> adj[], vector<int> visited, int curr)
{
    if(visited[curr]==2)
        return true;
    
    visited[curr] = 1;
    bool FLAG = false;
    for(int i=0;i<adj[curr].size();++i)
    {
        if(visited[adj[curr][i]]==1)
            visited[adj[curr][i]] = 2;
        else
        {
            FLAG = isCyclic_util(adj, visited, adj[curr][i]);
            if(FLAG==true)
                return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   vector<int> visited(V,0);
   bool FLAG = false;
   for(int i=0;i<V;++i)
   {
        visited[i] = 1;
        for(int j=0;j<adj[i].size();++j)
        {
            FLAG = isCyclic_util(adj,visited,adj[i][j]);
            if(FLAG==true)
                return true;
        }
        visited[i] = 0;
   }
   return false;
}

//  Method 2
bool findCycle(int pos, int vis[], vector<int> adj[], int parent)
{
    vis[pos] = true;
    
    for(int i=0; i<adj[pos].size(); i++){
        if(!vis[adj[pos][i]]){
            if(findCycle(adj[pos][i], vis, adj, pos))
                return true;
            }
        else if(adj[pos][i] != parent)
            return true;
    }
    return false;
}
bool isCyclic(vector<int> adj[], int V)
{
    int vis[V] = {false};
    
    for(int v=0; v<V; v++)
        if(!vis[v])
            if(findCycle(v, vis, adj, -1))
                return true;
            
    return false;
}