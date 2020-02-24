//Method 1
bool isCyclic_util(vector<int> adj[], vector<bool> visited, int curr)
{
    if(visited[curr]==true)
        return true;
    
    visited[curr] = true;
    bool FLAG = false;
    for(int i=0;i<adj[curr].size();++i)
    {
        FLAG = isCyclic_util(adj, visited, adj[curr][i]);
        if(FLAG==true)
            return true;
    }
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V,false);
   bool FLAG = false;
   for(int i=0;i<V;++i)
   {
           visited[i] = true;
           for(int j=0;j<adj[i].size();++j)
           {
               FLAG = isCyclic_util(adj,visited,adj[i][j]);
               if(FLAG==true)
                   return true;
           }
           visited[i] = false;
   }
   return false;
}

//  Method 2
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