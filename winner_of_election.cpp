#include <bits/stdc++.h>
using namespace std;

void findWinner(string str[], map<string, int> m, int n) {
    int res= 0;
    string s;
    for(auto x : m) {
        if(x.second > res) {
            res= x.second;
            s= x.first;
        }
    }
    cout<<s<<" "<<res<<"\n";
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string str[n];
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
        map<string, int> m;
        for(int i=0;i<n;i++) {
            getline(cin, str[i]);
            m[str[i]]++;
        }
        // for(auto x: m) {
        //     cout<<x.first<<" "<<x.second<<"\n";
        // }
        findWinner(str, m, n);
    }
    return 0;
}