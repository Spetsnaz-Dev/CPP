#include <bits/stdc++.h>
#define MAX 100
using namespace std;
bool isSafe(int i, int j, int grid[][MAX], bool vis[][MAX], int n){
    if(i<0 or i>=n or j<0 or j>=n or grid[i][j] == 0 or vis[i][j] == 1)
        return false;
    return true;
}
bool isPath(int i, int j, int grid[][MAX], bool vis[][MAX], int n)
{
    if(!isSafe(i, j, grid, vis, n))
        return false;
    
    vis[i][j] = 1;

    if(grid[i][j] == 2)
        return true;
    
    // check up
    if(isPath(i-1, j, grid, vis, n))
        return true;

    // check down
    if(isPath(i+1, j, grid, vis, n))
        return true;
    
    // check left
    if(isPath(i, j-1, grid, vis, n))
        return true;

    // check right
    if(isPath(i, j+1, grid, vis, n))
        return true;
    
    return false;
}
bool is_possible( int grid[MAX][MAX], int n )
{
    bool visited[MAX][MAX] = {{0}};
    bool flag = false;

    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < n; j++)
        {
            if(!visited[i][j] and grid[i][j] == 1){
                if(isPath(i, j, grid, visited, n)){
                    flag = true;
                    return flag;
                }
            }
        }
    }
    return flag;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int a[MAX][MAX];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin>> a[i][j];

		cout<< is_possible( a, n ) << endl;
	}
	return 1;
}