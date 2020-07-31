#include "bits/stdc++.h"
using namespace std;

int arr[4000][4000];
int pre[4000][4000];
int v1[4000], v2[4000];

int countSquares(vector<vector<int>>& arr, int target){
    int n = arr.size(), m = arr[0].size();
    
    vector<vector<int>> pre(n+1, vector<int>(m+1));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            pre[i + 1][j + 1] = arr[i][j];

    // prefix sum matrix
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];

    int count = 0;
    for (int i = 1; i <= n; i++) {
 
        for (int j = 1; j <= m; j++) {
 
            // min and max length of square submatrix
            int lo = 1, hi = min(n - i, m - j) + 1;
            bool found = false;
 
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int ni = i + mid - 1;
                int nj = j + mid - 1;

                int sum = pre[ni][nj] - pre[ni][j - 1] - pre[i - 1][nj] + pre[i - 1][j - 1];
 
                if (sum == target) {
                    // If sum X is found
                    if (sum == target) {
                        found = true;
                    }
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }
            if (found == true) {
                count++;
            }
        }
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n1, n2, s;
        cin>>n1>>n2>>s;

        char s1[2*n1], s2[2*n2];
        cin>>s1>>s2;

        vector<int> v1;
        for(int i=0; i<2*n1; i+=2){
            int t = ((s1[i] - '0') * 10) + s1[i+1];
            v1.push_back(t);
        }

        vector<int> v2;
        for(int i=0; i<2*n2; i+=2){
            int t = ((s2[i] - '0') * 10) + s2[i+1];
            v2.push_back(t);
        }

        vector<vector<int>> c(n1, vector<int>(n2));
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                c[i][j] = v1[i]+v2[j];
            }
        }
        cout<<countSquares(c, s)<<"\n";
    }
}