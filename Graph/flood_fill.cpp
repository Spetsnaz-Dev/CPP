#include<bits/stdc++.h>
using namespace std;
int arr[100][100];

void printPixels(int n, int m)
{
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }
        }
}

void floodFill(int n, int m, int x, int y, int newColor, int curr)
{
    if(x < 0 or x >= n or y < 0 or y >= m or arr[x][y] != curr)
        return;
    
    arr[x][y] = newColor;
    
    floodFill(n, m, x+1, y, newColor, curr);    //Down
    floodFill(n, m, x-1, y, newColor, curr);    //Up
    floodFill(n, m, x, y-1, newColor, curr);    //Left
    floodFill(n, m, x, y+1, newColor, curr);    //Right
}

int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        // int arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        int x,y,k;
        cin>>x>>y>>k;
        
        if(arr[x][y] != k)
            floodFill(n, m, x, y, k, arr[x][y]);
            
        printPixels(n, m);
        }
	return 0;
}