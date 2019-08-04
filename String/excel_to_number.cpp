#include<bits/stdc++.h>
using namespace std;
void printString(string str)
{
    int i=0;
    int n = str.length();
    //char str[52];
    int num = 0;
    for(i=0;i<str.length();i++)
    {
        //Similar to converting to decimal with 
        //base 26 instead of 10
        // num *= 26;
        // num += str[i] - 'A' -1;
        num = num * 26 + str[i] - 'A' +1;
    }
    cout<<num<<"\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        string n;
        cin>>n;
        printString(n);
    }
	return 0;
}