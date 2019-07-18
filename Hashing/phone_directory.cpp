//Phone directory
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <string> v;
        int i;
        for(i=0;i<n;i++)
        {
            string temp;
            cin>>temp;
            v.push_back(temp);
        }
        string query;
        cin>>query;
        int found[n];
        for(i=0;i<n;i++)
        {
            found[i] = -1;
        }
        for(i=0;i<n;i++)
        {
            int curr_index = 0;
            while(curr_index<v[i].length() && curr_index<query.length())
            {
                if(v[i][curr_index]==query[curr_index])
                {
                    found[i] = curr_index;
                }
                else
                {
                    break;
                }
                curr_index++;
            }
        }
        for(int j=0;j<query.length();j++)
        {
        	set <string> s;
            int flag = 0;
            for(i=0;i<n;i++)
            {
                if(found[i]!=-1)
                {
                    s.insert(v[i]);
                    found[i]--;
                    flag = 1;
                }
            }
            if(flag==0)
            {
                cout<<0;
            }
            else
            {
            	set <string> :: iterator it;
            	for(it=s.begin();it!=s.end();it++)
            	{
            		cout<<*it<<" ";
				}
			}
            cout<<"\n";
        }
    }
}