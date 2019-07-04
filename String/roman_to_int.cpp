//Convert Roman to Interger Number
#include<bits/stdc++.h>
using namespace std;

int value(char r) 
{ 
    if (r == 'I') 
        return 1; 
    if (r == 'V') 
        return 5; 
    if (r == 'X') 
        return 10; 
    if (r == 'L') 
        return 50; 
    if (r == 'C') 
        return 100; 
    if (r == 'D') 
        return 500; 
    if (r == 'M') 
        return 1000; 
  
    return -1; 
} 
void romanToDecimal(string str) {
    int res= 0;
    for(int i=0;i<str.length();i++) {
        int s1= value(str[i]);
        
        if(i+1 < str.length()) {
            int s2= value(str[i+1]);
        
        if(s1 >= s2) 
            res += s1;
        else {
            res += s2 - s1;
            i++;
        }
        } else {
            res += s1;
            i++;
        }
    }
    cout<<res<<"\n";
}

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        romanToDecimal(s);
    }
    return 0;
}