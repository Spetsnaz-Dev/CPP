#include<bits/stdc++.h>
using namespace std;
void check(string s) {
    set<char> st;
    for(int i=0;i<s.length();i++)
        st.insert(s[i]);
    for(auto i = st.begin();i!=st.end();i++)
        cout<<*i<<" ";
    //cout<<"\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        // check(s);
        int flag = s[0] == 'a' ? 1 : 0;
        cout<<flag<<"\n";
            }
	return 0;
}