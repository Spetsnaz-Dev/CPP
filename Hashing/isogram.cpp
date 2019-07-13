#include<bits/stdc++.h>
using namespace std;
bool checkIsogram(string str) {
    int n = str.length();
    unordered_map<char, int> mp;
    for(int i=0;i<n;i++) {
        mp[str[i]]++;
    }
    for(int i=0;i<n;i++) {
        if(mp[str[i]] != 1)
            return 0;
    }
    return 1;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        cout<<checkIsogram(s)<<"\n";
    }
    return 0;
}