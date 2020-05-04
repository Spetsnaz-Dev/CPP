// Giving a dictionary and a string ‘str’, your task is to find the longest string in dictionary of size x which can be formed by deleting some characters of the given ‘str’.
#include "bits/stdc++.h"
using namespace std;
bool isLCS(string str1, string str2)
{
    int m = str1.size(), n = str2.size();
    int i=0, j=0;

    for(; i<n and j<m; i++) {
        if(str1[j] == str2[i])
            j++;
    }
    return j == m;
}
string longestWordLCS(vector<string> v, string str)
{
    int count = 0;
    string res = "";
    int n = v.size(), m = str.size();
    for (int i = 0; i < n; i++) {
        if(count < v[i].size() and isLCS(v[i], str)){
            count = v[i].size();
            res = v[i];
        }
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        // Input
        int x;
        cin>>x;
        vector<string> v(x);
        for(int i=0; i<x; i++)
            cin>>v[i];
        string s;
        cin>>s;

        // Output
        cout<<longestWordLCS(v, s)<<"\n";
    }
    return 0;
}