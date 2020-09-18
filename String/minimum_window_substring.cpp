#include<bits/stdc++.h>
using namespace std;
void findSmallestWindow(string s, string t){
    int size_s = s.size(), size_t = t.size();
    
    if(size_s < size_t) {cout<<"-1\n"; return;}
    
    vector<int> h_str(128), h_pat(128);
    for(char c : t)
        h_pat[c]++;
    
    int start = 0, res = INT_MAX, min_index = -1, end = 0, len = 0, count = 0;
        for(end = 0; end < size_s; end++){
            h_str[s[end]]++;
            
            if(h_pat[s[end]] != 0 and h_str[s[end]] <= h_pat[s[end]])
                count++;
            
            if(count == size_t){
                // try to minimize window size
                while(h_pat[s[start]] == 0 or h_str[s[start]] > h_pat[s[start]]){
                    if(h_str[s[start]] > h_pat[s[start]])
                        h_str[s[start]]--;
                    start++;
                }
                int len = end - start + 1;
                if(res > len){
                    res = len;
                    min_index = start;
                }
            }
        }
    if(min_index == -1)
        cout<<"-1\n";
    else
        cout<<s.substr(min_index, res)<<"\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        string s, t;
        cin>>s;
        cin>>t;
        
        findSmallestWindow(s, t);
        }
	return 0;
}