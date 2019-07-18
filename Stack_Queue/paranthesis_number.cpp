#include<iostream>
#include<stack>
using namespace std;
void numberParanthesis(string str) {
    int lb_num=1;
    stack<int> rb_num;
    for(int i=0;i<str.length();i++) {
        if(str[i] == '(') {
            cout<<lb_num<<" ";
            rb_num.push(lb_num);
            lb_num++;
        }
        else if(str[i] == ')') {
            cout<<rb_num.top()<<" ";
            rb_num.pop();
        }
    }
    cout<<"\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        numberParanthesis(s);
    }
	return 0;
}