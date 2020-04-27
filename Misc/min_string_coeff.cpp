// Minimum String Coefficient

#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
using namespace std;

// solver function
int solve(string s, int p){
    int n = s.size();

    priority_queue<pair<int, int>> pq;
    map<int, int> mp;
    for (size_t i = 0; i < n; i++)
    {
        char curr = s[i];
        if(curr == '1'){
            int temp = i + 1;
            int count = 0;
            while(s[temp] == '0'){
                temp++;
                count++;
            }
            if(count > 0 and i < n-2 and temp != i+1){
                pq.push({count, i});
                mp[i] = count;
                // cout<<"count of 1 -> "<<count<<"\n";
            }
            else{ mp[i] = 0; }
        }
        else if(curr == '0'){
            int temp = i + 1;
            int count = 0;
            while(s[temp] == '1'){
                temp++;
                count++;
            }
            if(count > 0 and i < n-2 and temp != i+1){
                mp[i] = count;
                pq.push({count, i});
                // cout<<"count of 0 -> "<<count<<"\n";
            }
            else
                mp[i] = 0;
        }
    }
    while(!pq.empty() and p > 0) {
        pair<int, int> curr = pq.top();
        int count = curr.first;
        cout<<count<<"\n";
        int start = curr.second;
        int end = start + count;
        pq.pop();
        p--;
        if(s[start-1] == '0'){
            for(int i = start; i <= end; i++){
                s[i] = '0';
            }
        }
        else{
            for(int i = start; i <= end; i++){
                s[i] = '1';
            }
        }
    }
    cout<<s<<"\n";   //Check
    int a = 0;
    for (size_t i = 0; i < n; i++)
    {
        char curr = s[i];
        if(curr == '1'){
            int temp = i + 1;
            int count = 0;
            while(s[temp] == '0'){
                temp++;
                count++;
            }
            if(count > 0 and i < n-2 and temp != i+1){
                a += count;
                // cout<<"count of 1 -> "<<count<<"\n";
            }
        }
        else if(curr == '0'){
            int temp = i + 1;
            int count = 0;
            while(s[temp] == '1'){
                temp++;
                count++;
            }
            if(count > 0 and i < n-2 and temp != i+1){
                a += count;
                // cout<<"count of 0 -> "<<count<<"\n";
            }
        }
    }
    // for(auto i = mp.begin(); i != mp.end(); i++)
    //     cout<<i->first<<" -> "<<i->second<<'\n';
    return a;
}

int main()
{  
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    int n,p;
    cin>>n>>p;

    string s;
    cin>>s;

    cout<<solve(s, p)<<"\n";
        
    
    return 0;
}