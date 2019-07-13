#include<bits/stdc++.h>
using namespace std;

void findSpan(int price[], int n, int span[]) {
    stack<int> st;
    st.push(0);
    span[0] = 1;    //Default Span Value is 1

    for(int i=0;i<n;i++) {
        while((!st.empty()) && price[st.top()] <= price[i])
            st.pop();

        if(st.empty() == true)
            span[i] = i+1;
        else 
            span[i] = i - st.top();
            st.push(i);
    }
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int price[n];
        int s[n];
        for(int i=0;i<n;i++)
            cin>>price[i];
        findSpan(price, n, s);

        for(int i=0;i<n;i++)
            cout<<s[i]<<" ";
        cout<<"\n";
            }
	return 0;
}