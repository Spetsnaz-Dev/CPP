#include<bits/stdc++.h>
using namespace std;
void removeDuplicates(string str) {
    stack<char> st;
    for(int i=0; i< str.length(); i++) {
        if(str[i] == st.top() && !st.empty()) {
            st.pop();
        }
            else {
                st.push(str[i]);
            }
    }
    string s= "";
    int i=0;
    while(i<st.size()) {
        s += st.top();
        //cout<<st.top();
        st.pop(); i++;
    }
    s+= '\0';
    cout<<s<<"\n";
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        removeDuplicates(s);
    }
    return 0;
}