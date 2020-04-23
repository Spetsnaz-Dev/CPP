// Find the smallest Mother vertex in a directed graph
// https://practice.geeksforgeeks.org/problems/mother-vertex/1/?track=amazon-graphs&batchId=192
#include "bits/stdc++.h"
using namespace std;

void dfs(int x, vector<bool>& vis, vector<int> adj[]){
    vis[x] = true;
    
    for(int i=0; i<adj[x].size(); i++){
        if(!vis[adj[x][i]])
            dfs(adj[x][i], vis, adj);
    }
}
int findMother(int n, vector<int> adj[]) 
{ 
    // int n = adj.size();
    vector<bool> vis(n, 0);
    
    int mother = -1;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, vis, adj);
            mother = i;
        }
    }
    vector<bool> check(n, 0);
    dfs(mother, check, adj);
    for(int i=0; i<n; i++)
        if(check[i] == false)
            return -1;
            
    return mother;
} 

int main() 
{ 
    int T;
    cin>>T;
    while(T--){
        int num, edges;
        cin>>num>>edges;
        
        vector<int> adj[num];
        
        int u, v;
        while(edges--){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        cout<<findMother(num, adj)<<endl;
    }

	return 0;
}