#include "bits/stdc++.h"
using namespace std;

int countMatchedSubs(string s, char c)
{
    int n = s.length(), count = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != c)
            count++;
        else {
            sum += (count * (count + 1)) / 2;
            count = 0;
        }
    }
    sum += (count * (count + 1)) / 2;
    return sum;
}

// Function to print all sub strings
void subString(multimap<string, int> &mp, string s, int n) 
{
    for (int i = 0; i < n; i++) 
        for (int len = 1; len <= n - i; len++){
            string curr = s.substr(i, len);
            mp.insert({curr, 1});   
            // cout << s.substr(i, len) << endl;
        }
}
int findRes(multimap<string, int> &mp, string s, char c)
{
    bool ok = true;
    int count = 0;
    for(auto x : mp){
        for(char curr : x.first){
            if(curr == c){
                ok = false;
                break;
            }
        }
        if(ok)
            count++;
    }
    return count;
}
int main()
{
    string s;
    cin>>s;
    
    string str;
    char ch;

    // extract string
    int i = 0, n = s.size();
    while (i < s.size() and s[i] != ',')
    {
        if((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= '0' and s[i] <= '9'))
            str += s[i];
        i++;
    }

    // extract character
    i = s.size()-1;
    while (i >= 0 and s[i] != ',')
    {
        if((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= '0' and s[i] <= '9')){
            ch = s[i];
            break;
        }
        i--;
    }

    // multimap<string, int> mp;
    // subString(mp, str, str.size());
    // cout<<findRes(mp, str, ch)<<"\n";
    cout<<countMatchedSubs(str, ch)<<"\n";
}
