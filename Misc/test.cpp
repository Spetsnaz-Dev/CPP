#include<bits/stdc++.h>
#include<vector>
using namespace std;
long n, m, x, y, t;
long solve(int n, int m, int x, int y){
    long res = 0;
    vector<vector<int>> v(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int q = 0, w = 0; 
            if(i == 0 and j == 0){
                v[i][j] = max(x, y);
                res += v[i][j];
                continue;
            }
            if(i > 0)
                q = v[i-1][j];
            if(j > 0)
                w = v[i][j-1];
            v[i][j] = max(y - max(q, w), 0);
            res += v[i][j];
        }
    }
    // print matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // res += v[i][j];
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    return res;
}
int main(){
    cin>>t;
    while(t--){
    cin>>n>>m>>x>>y;
    cout<<solve(n, m, x, y)<<"\n";
    }
    return 0;
}