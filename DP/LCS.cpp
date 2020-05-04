// Find Longest Common Subsequence between two Strings
#include <bits/stdc++.h> 
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while (t--) {
	    int n,m;
	    cin>>n>>m;
        string s1,s2;
	    cin>>s1>>s2;

        int lcs[n+1][m+1];
	    for(int i = 0; i<= n; i++) {
	        for(int j = 0; j <= m ; j++) {
	            if(i==0||j==0)
                    lcs[i][j]= 0;
	            else if(s1[i-1] == s2[j-1])
	               lcs[i][j] = 1 + lcs[i-1][j-1];
	            else 
                    lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]); // for travelling previous max value forward
	        }
	    }
	   cout<<lcs[n][m]<<endl;
	}
	return 0;
}