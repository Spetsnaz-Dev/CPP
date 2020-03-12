#include<bits/stdc++.h>
using namespace std;

long long t, n;
long long findMaxGCD(long long arr[], long long n)
{
    return max(arr[0], arr[n-1]);
}

int main()
{
    //int t;
    clock_t start, end;
    cin>>t;
    while(t--)
    {
        //int n;
        cin>>n;
        long long arr[n];
        for(long long i= 0; i<n;i++)
            cin>>arr[i];
    //     start = clock(); 
        cout<<findMaxGCD(arr, n)<<"\n";
    //     end = clock();
    //     double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    // cout << "Time taken by program is : " << fixed  
    //      << time_taken << setprecision(5); 
    }
    return 0;
}

// 1 5 7 8 2 6