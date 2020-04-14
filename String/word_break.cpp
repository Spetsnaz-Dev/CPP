// #include <bits/stdc++.h>
// using namespace std;
// int findans(set<string> &dict,string b)
// {
//     if(b.empty())
//     {
//         return 1;
//     }
//     string check;
//     int result=0;
//     for(int i=0;i<b.length();i++)
//     {
//         check+=b[i];
//         // auto pos=dict.find(check);
//         if(dict.find(check) != dict.end())
//         {
//             int ans=findans(dict,b.substr(i+1));
//             result=max(result,ans);
//         }
//     }
    
//     return result;
// }

#include <bits/stdc++.h>
using namespace std;

int checkWordBreak(set<string>& st, string word)
{
    if(word.empty())
        return 1;
    
    int res = 0;
    string toFind;
    for(int i=0; i<word.size(); i++){
        toFind += word[i];
        if(st.find(toFind) != st.end()){
            int curr = checkWordBreak(st, word.substr(i+1));
            res = max(curr, res);
        }
    }
    return res;
}

int main()
{
    int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    set<string>dict;
	    while(n--)
	    {
	        string a;
	        cin>>a;
	        dict.insert(a);
	    }
	    
	    string b;
	    cin>>b;

	    cout<<checkWordBreak(dict,b)<<"\n";
	}
	return 0;
}