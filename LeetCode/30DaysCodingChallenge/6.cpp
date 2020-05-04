// Group Anagrams Together
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<vector<string> > groupAnagrams(vector<string> v)
{
    int n = v.size();
    vector<vector<string> > res(n);
    if(n == 0)
        return res;

    unordered_map<string, vector<string> > mp;

    for(int i=0; i<v.size(); i++){
        string s = v[i];
        sort(s.begin(), s.end());
        if(mp.find(s) != mp.end()) {
            mp[s].push_back(v[i]);
        }
        else
            mp[s].push_back(v[i]);
    }
    int k = 0;
    for(auto x : mp){
        if(x.second.size() >= 1)
        for(int i=0;i<x.second.size();i++){
            res[k].push_back(x.second[i]);
            }
            k++;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    vector<vector<string> > out = groupAnagrams(v);
    for(int i=0; i<out[i].size(); i++)
        for(auto word : out[i])
            cout<<word<<" ";
        // cout<<"\n";
    return 0;
}