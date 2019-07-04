#include<bits/stdc++.h>
using namespace std;

bool checkLeftRotate(string str1, string str2) {
    if(str1.length() != str2.length())
        return 0;
    int rotate_index = 2;
    int i=0;
    while(i < str1.length()) {
        if(str2[i] != str1[rotate_index]) {
            return 0;
        } 
        else {
            i++;
            rotate_index++;
            rotate_index = rotate_index % str1.length();
        }
    }
    return 1;
}
bool checkRightRotate(string str1, string str2) {
    if(str1.length() != str2.length())
        return 0;
    int rotate_index = str2.length() - 2;
    int i=0;
    while(i < str1.length()) {
        if(str2[i] != str1[rotate_index]) {
            return 0;
        } 
        else {
            i++;
            rotate_index++;
            rotate_index = rotate_index % str1.length();
        }
    }
    return 1;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s1, s2;
        cin>>s1>>s2;
        if(checkLeftRotate(s1, s2) || checkRightRotate(s1, s2))
            cout<<1<<"\n";
        else
            cout<<0<<"\n";
    }
    return 0;
}