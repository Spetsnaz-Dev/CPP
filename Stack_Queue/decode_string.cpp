#include <bits/stdc++.h>

using namespace std;

string convertStackToString(stack<char> st)
{
    string str="";
    while(!st.empty())
    {
        char ch = st.top();
        st.pop();
        str+=ch;
    }
    reverse(str.begin(),str.end());
    return str;
}

string solver(string str)
{
    stack<char> st;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]!=']')
            st.push(str[i]);
        else 
        {
            string tempStr = "";
            while(!st.empty() && st.top()!='[')
            {
                char ch = st.top();
                st.pop();
                tempStr+=ch;
            }
            reverse(tempStr.begin(),tempStr.end());
            st.pop();
            string count = "";
            while(!st.empty() && isdigit(st.top()))
            {
                count+=st.top();
                st.pop();
            }
            reverse(count.begin(),count.end());
            int times = stoi(count);
            for(int i=0;i<times;i++)
            {
                for(int j=0;j<tempStr.length();j++)
                {
                    st.push(tempStr[j]);
                }
            }
        }
    }
    return convertStackToString(st);
}

int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
        string str;
        cin>>str;
        cout<<solver(str)<<endl;
    }
    
    return 0;
}