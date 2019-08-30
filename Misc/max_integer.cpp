#include<iostream>
using namespace std;
void maxResult(string str) {
    int res= str[0] - '0';
    for(int i=1;i<str.length();i++) {
        //int digit = str[i] - '0';
        if(str[i] == '0' || str[i] == '1' || res <2)
            res += (str[i] - '0');
        else
        res *= (str[i] - '0');
    }
    cout<<res<<"\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        maxResult(s);
    }
	return 0;
}