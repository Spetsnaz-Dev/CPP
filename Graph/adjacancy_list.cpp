//print adjacancy list of a graph
#include<bits/stdc++.h>
using namespace std;
// void addEdge(vector<int> arr[], int edge, int vertex)
// {
//     arr[edge].push_back(vertex);
//     arr[vertex].push_back(edge);
// }
void printGraph(vector<int> arr[], int v)
{
    for(int i=0;i<v;i++){
        cout<<i;
        for(int j=0;j<arr[i].size();j++)
            cout<<"-> "<<arr[i][j];
        cout<<"\n";
    }
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int v,e;
        cin>>v>>e;
        //int n_vertex = v;
        int edge, vertex;
        vector<int> arr[v];
        for(int i=0;i<e;i++)
        {
            cin>>edge>>vertex;
            arr[edge].push_back(vertex);
            arr[vertex].push_back(edge);
            //addEdge(arr, edge, vertex);
        }
        printGraph(arr, v);
        }
	return 0;
}