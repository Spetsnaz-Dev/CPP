#include<bits/stdc++.h>
using namespace std;

string isAnagram(string str1, string str2) {
    if(!str1 && !str2)
        return "YES";
    int n1= str1.length();
    int n2= str2.length();
    if(n1 != n2)
        return "NO";
    int xor_result= 0;
    for(int i=0;i<n1;i++) {
        xor_result = xor_result ^ str1[i];
        xor_result = xor_result ^ str2[i];
    }
    if(xor_result == 0)
        return "YES";
    else 
        return "NO";
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        string str1, str2;
        cin>>str1>>str2;

        cout<<isAnagram(str1, str2)<<"\n";
    }
}