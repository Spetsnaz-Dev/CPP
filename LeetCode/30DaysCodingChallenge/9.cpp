// Backspace String Compare
#include "bits/stdc++.h"
using namespace std;
bool backspaceStringCompare(string &s, string &t)
{
    int sizeS = s.size(), sizeT = t.size(), i = 0;
    while (i < sizeS) {
        if(s[i] == '#' and i < 1){
            s.erase(s.begin()+i, s.begin()+i+1);
            sizeS--;
            continue;
        }
        else if(s[i] == '#'){
            s.erase(s.begin()+i-1, s.begin()+i+1);
            i -= 1;
            sizeS -= 2;
        }
        else
            i++;
    }
    i = 0;
    while (i < sizeT) {
        if(t[i] == '#' and i < 1){
            t.erase(t.begin()+i, t.begin()+i+1);
            sizeT--;
            continue;
        }
        else if(t[i] == '#'){
            t.erase(t.begin()+i-1, t.begin()+i+1);
            i -= 1;
            sizeT -= 2;
        }
        else
            i++;
    }
    // cout<<"S is - "<<s<<"\n";
    // cout<<"T is - "<<t<<"\n";
    return s == t;
}
int main()
{
    string s, t;
    cin>>s;
    cin>>t;
    // s.erase(s.begin()+1, s.begin()+3);
    // cout<<s;
    cout<< backspaceStringCompare(s, t)<<"\n";

    return 0;
}