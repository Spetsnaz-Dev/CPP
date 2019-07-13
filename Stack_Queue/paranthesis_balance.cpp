#include<bits/stdc++.h>
using namespace std;

int paranthesisBalance(string str) {
    stack<char> st;
    for(int i=0;i< str.length();i++) {
        if((str[i] == '(') || (str[i] == '{') || (str[i] == '[')) 
            st.push(str[i]);
        
        if((str[i] == ')') || (str[i] == '}') || (str[i] == ']')) {

            if(st.empty() == true)
                return 0;

            else if((str[i] == ')') && (st.top() == '('))
                st.pop();

            else if((str[i] == '}') && (st.top() == '{'))
                st.pop();

            else if((str[i] == ']') && (st.top() == '['))
                st.pop();
            else
                return 0; 
        }
    }
    if(!st.empty())
        return 0;
    else return 1;
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int res= paranthesisBalance(s);
        if(res == 1)
            cout<<"balanced"<<"\n";
        else cout<<"not balanced"<<"\n";
    }
	return 0;
}