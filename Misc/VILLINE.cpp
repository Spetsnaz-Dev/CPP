#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n;
    cin>>n;
    int m,c;
    cin>>m>>c;
    int x[n], y[n], p[n];
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i]>>p[i];
    
    int upRiver = 0, downRiver = 0;
    for(int i=0;i<n;i++)
    {
        if(y[i] < (m*x[i] + c))
            downRiver += p[i];
        else
            upRiver += p[i];
    }
    cout<<max(upRiver, downRiver)<<endl;

    return 0;
}