// The expansion of nCr can always be reduced to product of integers. This is done by canceling out terms in denominator. This approach is applied in the function given below.

// This function has time complexity of O(n^2 * log(n)). This will calculate nCr % m for n<=10000 under 1 sec.

// #include <numeric>
// #include <algorithm>
// int M=1e7+7;
// int ncr(int n, int r)
// {
//     r=min(r,n-r);
//     int A[r],i,j,B[r];
//     iota(A,A+r,n-r+1);  //initializing A starting from n-r+1 to n
//     iota(B,B+r,1);      //initializing B starting from 1 to r

//     int g;
//     for(i=0;i<r;i++)
//     for(j=0;j<r;j++)
//     {
//         if(B[i]==1)
//             break;
//         g=__gcd(B[i], A[j] );
//         A[j]/=g;
//         B[i]/=g;
//     }
//     long long ans=1;
//     for(i=0;i<r;i++)
//         ans=(ans*A[i])%M;
//     return ans;
// }
//Find nCr of large numbers
#include<bits/stdc++.h>
using namespace std;

int M=1e7+7;
int ncr(int n, int r)
{
    r=min(r,n-r);
    int A[r],i,j,B[r];
    iota(A,A+r,n-r+1);  //initializing A starting from n-r+1 to n
    iota(B,B+r,1);      //initializing B starting from 1 to r

    int g;
    for(i=0;i<r;i++)
    for(j=0;j<r;j++)
    {
        if(B[i]==1)
            break;
        g=__gcd(B[i], A[j] );
        A[j]/=g;
        B[i]/=g;
    }
    long long ans=1;
    for(i=0;i<r;i++)
        ans=(ans*A[i])%M;
    return ans;
}
void printRes(int a)
{
    int arr[a] = {0};
    int i, r= a/2;
    for(i=0;i<=r;i++){
        arr[i] = ncr(a,i+1);
    }
    if(a & 1)
        arr[i] = arr[0];
    int size = sizeof(arr)/sizeof(arr[0]);
    int res[2*size];
    for(int i=0;i<size;i++)
        res[i] = arr[i];
    
    for(int i=0;i<a;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    printRes(n);

    return 0;
}