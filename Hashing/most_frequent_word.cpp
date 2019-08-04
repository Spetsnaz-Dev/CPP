#include<bits/stdc++.h>
using namespace std;
void findFrequency(string s, int n)
{
    unordered_map<string, int> m;
    for(int i=0;i<s.length();i++)
        m[s[i]]++;
    int c=0, str;
    for(auto i : m)
    {
        if(i->second > c){
            c= i->second;
            s = i->first;
        }
    }
    cout<<s<<"\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        for(int i=0;i<n;i++)
            cin>>s[i];
        findFrequency(s, n);
    }
	return 0;
}