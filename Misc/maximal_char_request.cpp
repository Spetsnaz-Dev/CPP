#include "bits/stdc++.h"
// #define mod 1000000007;
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    vector<vector<int>> freq(26, vector<int>(n, 0));
    int c;
    for(int i=0; i<26; i++){
        c = tolower(s[i]) - 'a';
        freq[c][i]++;
    }
    for(int i=0; i<26; i++){
        for(int j=1; j<n; j++){
            freq[i][j] += freq[i][j-1];
        }
    }

    vector<int> ans;
    for(int i=0; i<queries.size(); i++){
        int low = queries[i][0], high = queries[i][1];
        int a=0;
        for(int j = 25; j >= 0; j--){
            a=freq[j][high];
            if(low > 0)
                a-=freq[j][low-1];
            if(a>0){
                // cout<<a<<"\n";
                break;
            }
        }
        ans.push_back(a);
    }
    return ans;
}
