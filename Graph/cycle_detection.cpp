/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool returnCyclic(int v, int vis[], int recStack[], vector<int> adj[])
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
    int recStack[V] = {  false  };
    int vis[V] = {  false };
    
    for(int i=0;i<V;i++)
        if(returnCyclic(i, vis, recStack, adj))
            return true;
            
    return false;
}