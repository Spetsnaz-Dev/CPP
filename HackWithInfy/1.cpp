#include<bits/stdc++.h>
using namespace std;
int n,m;
int solve(int arr[n][m])
int main()
{
    cin>>n>>m;
    int arr[n][m];
    char ele;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>arr[i][j];

    string str;
    cin>>str;
    
    cout<<solve(arr, str)<<"\n";

    return 0;
}