#include<bits/stdc++.h>
using namespace std;
void concatString(string s, string r)
{
    unordered_map<char, int> mp1;
    for(int i=0;i<s.size();i++){
        char c = s[i];
        mp1[c]++;
    }
    unordered_map<char, int> mp2;
    for(int i=0;i<r.size();i++){
        char c = r[i];
        mp2[c]++;
    }
    string res= "";
    for(int i=0;i<s.size();i++){
        char c = s[i];
        if(mp2.find(c) == mp2.end())
            res += c;
    }
    for(int i=0;i<r.size();i++){
        char c = r[i];
        if(mp1.find(c) == mp1.end())
            res += c;
    }
    //string result = s + res;
    if(res == ""){
        cout<<"-1\n";
        return;
    }
    else cout<<res<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,r;
        cin>>s>>r;
        concatString(s, r);
    }
    return 0;
}