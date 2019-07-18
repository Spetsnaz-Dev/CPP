//Most frequent word in an array of strings
#include<bits/stdc++.h>
using namespace std;
void printMostFrequentWord(string str[], int n, map<string, int> mp)
{
    // ["geeks", "for", "geeks", "greek", "greek"] ==> greek
    int count=0;
    string res= "";
    map<string, int> :: iterator x;
    for(x = mp.begin(); x!= mp.end(); x++)
    {
        if(x->second > count)
        {
            count = x->second;
            res = x->first;
        }
    } 
    cout<<res<<"\n";
}
int main()
{
    int t;
    cin>>t;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    while(t--)
    {
        int n;
        cin>>n;
        string str[n];
        map<string, int> mp;
        for(int i=0;i<n;i++)
        {
            cin>>str[i];
            //getline(cin, str[i]);
            mp[str[i]]++;   
            cout<<mp[str[i]]<<endl;
        }
        printMostFrequentWord(str, n, mp);
    }
    return 0;
}