#include "bits/stdc++.h"
using namespace std;

string abbreviation(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();

    unordered_set<char> st;
    unordered_set<char> temp;

    int countUpperS1 = 0;
    for(int i=0; i<n1; i++){
        if(s1[i] < 97)
            countUpperS1++;
    }
    int countUpperS2 = 0;
    for(int i=0; i<n2; i++){
        if(s2[i] < 97)
            countUpperS2++;
    }
    
    char c;
    for(int i=0; i<n1; i++)
        st.insert(s1[i]);

    for(int i=0; i<n2; i++){
        int r = (int) s2[i];
        if(st.find(s2[i]) == st.end()){
            char t = tolower(s2[i]);
            if(st.find(t) == st.end())
                return "NO";
            else
                countUpperS2--;
        }
        else{
                countUpperS1--;
                countUpperS2--;
            }
        }
    if(countUpperS1 <= 0 and countUpperS2 <= 0)
        return "YES";
    else
        return "NO";
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s1, s2;
        cin>>s1>>s2;
    
        cout<<abbreviation(s1, s2)<<"\n";
    }
    return 0;
}