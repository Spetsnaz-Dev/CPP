#include <bits/stdc++.h> 
#define pb push_back
using namespace std;

string solve(string s1, string s2, int n){
    int c1 = 0, c2 = 0, c3 = 0;

    for(int i=0; i<n; i++){
        if(s1[i] > s2[i])
            c1++;
        else if(s1[i] < s2[i])
            c2++;
        else
            c3++;
    }

    if(c1 > c2)
        return "RED";
    else if(c1 < c2)
        return "BLUE";
    return "EQUAL";
}
int main() 
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string s1, s2;
        cin>>s1;
        cin>>s2;
        cout<<solve(s1, s2, n)<<"\n";
    }
    return 0;
} 