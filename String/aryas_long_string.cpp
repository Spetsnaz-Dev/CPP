#include<bits/stdc++.h>
using namespace std;

void getCount(string s, int k, int n, char key) {
    string str= "";
    while(k--) {
        str += s;
    }
    if(n > str.length())
        {
            cout<<0<<"\n";
            return;
        }
    //cout<<n<<endl;
    int count = 0;
    for(int i=0; i < n; i++) {
        if(str[i] == key)
            count++;
    }
    cout<<count<<"\n";
}
int main() {
    int t;
    cin>>t;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(t--) {
        string s;
        getline(cin, s);
        long long k, n;
        cin>>k>>n;
        char key;
        cin>>key;
        getCount(s, k, n, key);
    }
    return 0;
}