//Find the Longest Common Substring which is present in both the Strings
#include <bits/stdc++.h> 
using namespace std;

void patternSearch(string str1, string str2) {
    int n1= str1.length();
    int n2= str2.length();

    int max_length=0;
    int table[n1+1][n2+1];
    memset(table, 0, sizeof(table)); //set initial table values to 0
    //cout<<table[1][2]<<endl;
    for(int i=1;i<=n1;i++) {
        for(int j=1;j<=n2;j++) {
            if(str1[i-1] == str2[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
                if(max_length < table[i][j])
                    max_length= table[i][j];
            }
        }
    }
    cout<<max_length<<"\n";
}
// Driver program to test above function 
int main() 
{ 
    int t;
    cin>>t;
    while(t--) {
        int n1,n2;
        cin>>n1>>n2;
        string s1, s2;
        cin>>s1>>s2;
        patternSearch(s1, s2); 
    }
    return 0; 
} 