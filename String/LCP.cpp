//Find the Longest Common Prefix which includes in both thr Strings
#include<bits/stdc++.h>
using namespace std;

void LCP(string str1, string str2) {
    int n= str1.length();
    int i=0,j=0;
    int max= 0, start=0;
    for(i=0;i<n;i++) {
        if(str2[i] == str1[j]) {
            j++;
            if(j > max) {
                max= j;
                start= i;
            }
        } else j=0;
    }
    if(max== 0)
        cout<<"-1 ";
    else {
        cout<<start-max+1<<" ";
        i=0;
        while(i<max)
            cout<<str1[i++];
    }
    cout<<"\n";
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s1, s2;
        cin>>s1>>s2;
        LCP(s1, s2);
    }
    return 0;
}