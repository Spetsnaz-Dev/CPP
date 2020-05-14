#include<bits/stdc++.h>
using namespace std;
void minimize(string s, int k)
{
    // if(s.size() <= k){
    //     cout<<"0\n";
    //     return;
    // }
    
    int freq[26] = {0};
    for(int i=0; i<s.size(); i++)
    {
        int c = s[i] - 'a';
        freq[c]++;
    }
    for(int i=0; i<26;i++)
        while(freq[i] > 1 and k > 0){
            k--;
            freq[i]--;
        }
    for(int i=0; i<26;i++)
    {
        while(k > 0 and freq[i] > 0){
            k--;
            freq[i]--;
        }
    }
    
    long val = 0;
    for(int i=0; i<26; i++){
        if(freq[i] != 0)
            val += freq[s[i]] * freq[s[i]];
    }
    cout<<val<<"\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        
        int k;
        cin>>k;
        minimize(s, k);
        }
	return 0;
}