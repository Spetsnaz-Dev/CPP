//Longest Distinct characters in string
#include<bits/stdc++.h>
using namespace std;

int distinctCharacters(string str) {
    int len = str.length();
    int lastIndex= 0, max_len= 0;
    set<char> s;
    for(int i=0;i<len;i++) {
        if(s.find(str[i]) != s.end()) {
            if(max_len < s.size())
                max_len = s.size();
            while(s.find(str[i]) != s.end())
                s.erase(str[lastIndex++]);
        }
        s.insert(str[i]);
    }
    //cout<<s.size()<<"\n";
    int res;
    max_len > s.size() ? res= max_len : res= s.size();
    return res;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        cout<<distinctCharacters(s)<<"\n";
    }
    return 0;
}