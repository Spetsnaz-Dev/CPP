// https://practice.geeksforgeeks.org/contest-problem/sub-array-of-given-sum-in-2-d-array/1/
#include <bits/stdc++.h>
#define N 50
using namespace std;

bool check_in_row( int* r, int n, int x )
{
    // this function looks for x in given 1D array in O(n) time
    int sum=0, start=0, end=0;
    
    while(1)
    {
        if(sum==x)
            return true;
        if(sum>x)
        {
            // reducing window if sum is too large
            sum -= r[start];
            start++;
        }
        else
        {
            // increasing window if sum is too small
            if(end==n)
                return false;
            sum+= r[end];
            end++;
        }
    }
}

bool is_rectangle_there(int arr[N][N], int n, int x)
{
    int** sum_arr = new int*[n];
    for(int i=0; i<n; i++)
    {
        sum_arr[i] = new int[n];
        for(int j=0; j<n; j++)
            sum_arr[i][j]=0;
    }
    
    for(int i=0; i<n; i++)
        for(int j=i; j>=0; j--)
        {
            for(int k=0; k<n; k++)
                sum_arr[j][k] += arr[i][k];
                // adding ith row of arr to jth row of sum_arr
            
            if( check_in_row( sum_arr[j], n, x ) )
                // looking for sum in jth row of sum_arr
                return true;
        }
    return false;
}

int main()
{
    int arr[N][N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>> arr[i][j];
        
        int x;
        cin>>x;
        
        if( is_rectangle_there(arr,n,x) )
            cout<< "Yes" << endl;
        else
            cout<< "No" << endl;
    }
	return 0;
}