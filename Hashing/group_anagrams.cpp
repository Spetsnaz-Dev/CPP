//Group Anagrams Together
#include<bits/stdc++.h>
using namespace std;
void groupAnagrams(map<string, int> mp)
{
    vector<int> v;
    for(auto i : mp){
        v.push_back(i.second);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    //cin.ignore("\n");
    while (t--)
    {
        int n;
        cin>>n;
        string str[n];
        map<string, int> mp;
        for(int i=0;i<n;i++){
            cin>>str[i];
            string temp = str[i];
            sort(temp.begin(), temp.end());
            mp[temp]++;
        }
        groupAnagrams(mp);
    }
    return 0;
}