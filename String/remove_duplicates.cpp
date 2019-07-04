//Remove duplicates from a String
#include<bits/stdc++.h>
using namespace std;
main()
{
    int t;
    cin>>t;
    cin.ignore();                        

    while(t--)
    {
        
      unordered_map<char,int> m;

      string s;
      getline(cin,s);

      for(int i=0;i<s.size();i++)
        {
            if(m[s[i]]==0)                                    //if value not equals to zero print
            {
                cout<<s[i];                                   //print
                m[s[i]]=1;                                    //assigning zero so that does not get printed again
            }

        }

cout<<endl;
    }
}
