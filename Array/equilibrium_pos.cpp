
//Find Equilibrium Point
#include <iostream> 
using namespace std; 
int main() 
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        if(n==1)
        cout<<1<<"\n";
        
    else if(n>1)
    {
        int i,lsum=arr[0], rsum= 0;
        //cout<<lsum<<" -LSUM\n";

        for(i=2;i<n;i++)
            rsum+=arr[i];
        //cout<<rsum<<" -RSUM\n";

        int flag=0;

        for(i=1;i<n;i++)
            {
                if(lsum == rsum) {
                    cout<<i+1<<"\n";        //Answer
                    flag=1;
                    break;
                }
                lsum+= arr[i];
                rsum-= arr[i+1];
            }
            if(flag==0)
                cout<<-1<<"\n"; //Answer
    }
    }
    //int arr[]= { 1, 3, 5, 2, 2, 6, 1 };
    //int n= sizeof(arr)/sizeof(arr[0]);
    return 0;
}