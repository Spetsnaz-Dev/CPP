#include<bits/stdc++.h>
using namespace std;

char printIndex(string s, int index) {
    return s[index];
}

string rightRotate(string str, int index) {
    int n= str.length();
    int low= 0, high = n-1;

    //Reverse the whole String
    char container;
    while(low < high) {
        container = str[low];
        str[low++] = str[high];
        str[high--] = container;
    }
    //Reverse String from 0 to K
    high= index-1; low= 0;
    while(low < high) {
        container= str[low];
        str[low++] = str[high];
        str[high--] = container;
    }
    //Reverse string from K+1 to N-1
    low= index; high= n-1;
    while(low < high) {
        container= str[low];
        str[low++] = str[high];
        str[high--] = container;
    }
    return str;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, queries;
        cin>>n>>queries;
        string s;
        cin>>s;
        string str= s;
        while(queries--) {
            int type, index;
            cin>>type>>index;
            if(type == 1) {
                str =rightRotate(str, index);
                cout<<str<<"\n";
            }
            else if(type == 2)
                cout<<printIndex(str, index)<<"\n";
        }        
    }
}