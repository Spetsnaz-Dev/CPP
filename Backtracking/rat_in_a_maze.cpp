bool isSafe(int row, int col, int m[][MAX], int n, int visited[][MAX])
{
    if( row == -1 || row == n ||
        col == -1 || col == n ||
        visited[row][col] || m[row][col] == 0)
        return false;
    return true;
}
void printPathUtil(int row, int col, int m[][MAX], int n, vector<string> &allPaths, string &path, int visited[][MAX])
{
    if( row == -1 || row == n ||
        col == -1 || col == n ||
        visited[row][col] || m[row][col] == 0 )
        return;
    
    if( row == n-1 && col == n-1){
        allPaths.push_back(path);
        return;
    }
    visited[row][col] = 1;
    
    //go-down
    if(isSafe(row+1, col, m, n, visited)){
        path += 'D';
        printPathUtil(row+1, col, m, n, allPaths, path, visited);
        path.pop_back();
    }
    //go-left
    if(isSafe(row, col-1, m, n, visited)){
        path += 'L';
        printPathUtil(row, col-1, m, n, allPaths, path, visited);
        path.pop_back();
    }
    //go-right
    if(isSafe(row, col+1, m, n, visited)){
        path += 'R';
        printPathUtil(row, col+1, m, n, allPaths, path, visited);
        path.pop_back();
    }
    //go-up
    if(isSafe(row-1, col, m, n, visited)){
        path += 'U';
        printPathUtil(row-1, col, m, n, allPaths, path, visited);
        path.pop_back();
    }
    visited[row][col] = 0;
}
vector<string> printPath(int m[MAX][MAX], int n)
{
    vector<string> allPaths;
    string path;
    int visited[n][MAX];
    memset(visited, 0, sizeof(visited));
    
    printPathUtil(0, 0, m, n, allPaths, path, visited);
    
    for(int i=0; i<allPaths.size();i++)
        cout<<allPaths[i]<<" ";
}
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector<string> printPath(int m[MAX][MAX], int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
	int m[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>m[i][j];
		}
	}
	
	vector<string> res = printPath(m,n);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;
}
	return 0;
}