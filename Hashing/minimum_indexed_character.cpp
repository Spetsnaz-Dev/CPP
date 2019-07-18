//Minimumm Indexed Character
#include<bits/stdc++.h>
using namespace std;
void findIndex(string str, string patt)
{
    unordered_map<char, int> mp;
    for(int i=0;i<patt.length();i++)
        mp[patt[i]] = i;
    
    for(int i=0;i<str.length();i++)
    {
        if(mp.find(str[i]) != mp.end())
        {
            cout<<str[i]<<"\n";
            return ;
        }
    }
    cout<<"$"<<"\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        string str, patt;
        cin>>str;
        cin>>patt;
        //cout<<str<<" -- "<<patt<<endl;
    findIndex(str, patt);
    }
	return 0;
}