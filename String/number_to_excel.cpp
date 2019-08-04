#include<bits/stdc++.h>
using namespace std;
void printString(int n)
{
    int i=0;
    char str[52];
    
    while(n>0)
    {
        int r = n%26;
        if(r == 0)
        {
            str[i++] = 'Z';
            n = (n/26) -1;
        }
        else
        {
            str[i++] = (r-1) + 'A';
            n /= 26;
        }
    }
    reverse(str, str+strlen(str));
    cout<<str<<"\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        printString(n);
    }
	return 0;
}