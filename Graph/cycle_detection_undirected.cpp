/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/
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