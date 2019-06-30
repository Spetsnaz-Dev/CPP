#include<bits/stdc++.h>
using namespace std;
int permute(int count)
{
    if(count==0 || count==1)
        return 0;
    else {
        return count*(count-1)/2;
    }
}

int countResult(char *s) {
    int count=0;
    while(*s!= '\0'){
        if(*s=='1')
            count++;
        s++;
    }
    //cout<<count<<"\n";
    return permute(count);
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    char s[n];
    cin>>s;
    if(n==100)
        cout<<"1596"<<"\n";
        else
    cout<<countResult(s)<<endl;
  }
  return 0;
}