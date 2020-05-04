#include "bits/stdc++.h"
using namespace std;

string abbreviation(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();

    unordered_set<char> st;
    
    char c;
    for(int i=0; i<n1; i++){
        c = toupper(s1[i]);
        st.insert(c);
    }
    
    for(int i=0; i<n2; i++){
        c = toupper(s2[i]);
        if(st.find(c) == st.end())
            return "NO";
    }
    return "YES";
}
int main()
{
    string s1, s2;
    cin>>s1>>s2;
    
    cout<<abbreviation(s1, s2)<<"\n";

    return 0;
}