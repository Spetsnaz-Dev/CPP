#include<bits/stdc++.h>
using namespace std;


 int max_path_sum(int [], int [], int , int );

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        int result = max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}

// } Driver Code Ends

/*You are required to complete this method*/
 int max_path_sum(int ar1[], int ar2[], int m, int n)
{
    int sum1 = 0, sum2 = 0, result = 0;
    int i = 0, j = 0;
    
    while (i < m and j < n) 
    { 
        if (ar1[i] < ar2[j]) 
            sum1 += ar1[i++]; 
        else if (ar1[i] > ar2[j]) 
            sum2 += ar2[j++]; 
  
        else  // we reached a common point 
        { 
            // Take the maximum of two sums and add to result 
            result += max(sum1, sum2); 
  
            // Update sum1 and sum2 for elements after this 
            // intersection point 
            sum1 = 0, sum2 = 0; 
  
            // Keep updating result while there are more common 
            // elements 
            while (i < m &&  j < n && ar1[i] == ar2[j]) 
            { 
                result = result + ar1[i++]; 
                j++; 
            } 
        } 
    } 
  
    // Add remaining elements of ar1[] 
    while (i < m) 
        sum1  +=  ar1[i++]; 
  
    // Add remaining elements of ar2[] 
    while (j < n) 
        sum2 +=  ar2[j++]; 
  
    // Add maximum of two sums of remaining elements 
    result +=  max(sum1, sum2); 
  
    return result; 
}