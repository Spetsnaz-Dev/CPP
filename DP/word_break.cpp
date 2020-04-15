// Word Break Problem
#include <bits/stdc++.h>
using namespace std;

bool checkWordBreak(set<string>& st, string word)
{
    int size = word.size();

    if(size==0)
        return 1;
    
    bool dp[size+1] = {false};
    for(int i=1; i<=size; i++){
        // Find for any prefix string from 0th position
        if(!dp[i] and st.find(word.substr(0, i)) != st.end())
            dp[i] = true;
        
        if(dp[i]){
            if(i == size)
                return true;
            // Find for any suffix string after i'th position
            for(int j=i+1; j<=size; j++){
                if(!dp[j] and st.find(word.substr(i, j-i)) != st.end())
                    dp[j] = true;
            
                if(j == size and dp[j])
                    return true;
            }
        }
    }
    return false;
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