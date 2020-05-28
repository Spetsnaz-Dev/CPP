#include "bits/stdc++.h"
using namespace std;

string smallestWindow (string s, string patt){
    int n = s.size(), m = patt.size();
    if(n < m)
        return "-1";
    
    vector<int> v1(128), v2(128);
    for(int i=0; i < m; i++)
        v1[patt[i]]++;
    
    int start = 0, i = 0, min_len = INT_MAX, count = 0, start_idx = -1;    
    for(i = 0; i < n; i++)
    {
        v2[s[i]]++;

        if(v1[s[i]] != 0 and v1[s[i]] >= v2[s[i]])
            count++;
        
        if(count == m)
        {
            while (v1[s[start]] == 0 or v2[s[start]] > v1[s[start]])
            {
                if(v2[s[start]] > v1[s[start]])
                    v2[s[start]]--;
                start++;
            }
            int curr_len = i - start + 1;
            if(min_len > curr_len){
                min_len = curr_len;
                start_idx = start;
            }
        }
    }
    if(start_idx != -1)
        return s.substr(start, min_len);
    else
        return "-1";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s, patt;
        cin>>s;
        cin>>patt;
        cout<<smallestWindow(s, patt)<<"\n";
    }
    return 0;
}