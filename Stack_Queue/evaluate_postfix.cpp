#include<bits/stdc++.h>
using namespace std;
void evaluatePostfix(string str) {
    stack<int> st;
    int res=0;
    for(int i=0;i<str.length();i++) {
        //int element = str[i] - '0';
        if(isdigit(str[i])) {
            st.push(str[i] - '0');
            //cout<<st.top();
        }
        else {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();

            switch(str[i]) {
                case '+' :
                res = val1 + val2;
                st.push(res);
                break;

                case '-' :
                res= val1 - val2;
                st.push(res);
                break;

                case '*' :
                res= val1 * val2;
                st.push(res);
                break;

                case '/' :
                res = val1 / val2;
                st.push(res);
                break;
            }
        }
    }
    cout<<st.top()<<"\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        evaluatePostfix(str);
    }
	return 0;
}