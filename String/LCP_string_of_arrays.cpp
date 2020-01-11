//Longest Common Prefix in an Array of Strings
#include<bits/stdc++.h>
using namespace std;

string findLCP_Of_Array(string str[], int len) {
    if(len == 1)
        return str[0];
    sort(str, str+len);
    int last = min(str[0].length(), str[len-1].length());
    int i=0;
    while(i < last && str[0][i] == str[len-1][i])
        i++;
    if(i==0)
        return "-1";
    else
    {
    string s= "";
    for(int j=0;j<i;j++)
        s += str[0][j];
    return s;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int len;
        cin>>len;
        string str[len];
        //string s[] = {"geeksforgeeks", "geeks", "geek", "geezer"}; 
        for(int i=0;i<len;i++) {
            cin>>str[i];
        }
        cout<<findLCP_Of_Array(str, len)<<"\n";
    }
    return 0;
}