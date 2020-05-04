// 
#include "bits/stdc++.h"
using namespace std;

bool checkValidString(string s) {
    stack<int> st, stars;

    int i=0;
    while (i < s.size())
    {
        if(s[i] == '(')
            st.push(i);
        else if(s[i] == '*')
            stars.push(i);
        else
        {
            if(!st.empty())
                st.pop();
            else if(!stars.empty())
                stars.pop();
            else
                return false;
        }
        i++;
    }
    while (!st.empty() and !stars.empty())
    {
        if(st.top() > stars.top())
            return false;
        else { st.pop(); stars.pop(); }
    }
    return st.empty();    
}
int main()
{
    string s;
    cin>>s;

    cout<<checkValidString(s)<<"\n";

    return 0;
}