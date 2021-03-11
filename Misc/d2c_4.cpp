#include "bits/stdc++.h"
#define pb push_back
using namespace std;

bool isOdd(int n){return n % 2 != 0 ? 1 : 0;}
bool isEven(int n){return n % 2 == 0 ? 1 : 0;}

int solve(vector<int> &arr)
{
    int n = arr.size(), res = 0, count = 1, start = 0;

    for(int i=0; i<n; i++){
        if(i+1 < n and (((isOdd(arr[i]) and isEven(arr[i+1])) or ((isEven(arr[i]) and isOdd(arr[i+1]))))))
            count++;
        else{
            int len = i - start;
            res += (len * (len-1))/2;
            start = i+1;
        }
    }
    return res;
}
int main()
{   
    int n;
    cin>>n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin>>v[i];

    // Output
    cout<<solve(v)<<"\n";
}




//  for (int i=0; i <n; i++) //This loop will select start element
//  {
//  for (int j=i; j<n; j++)   //This loop will select end element
//  {
//  for (int k=i; k<=j; k++) //This loop will print element from start to end
 
//  {
//  System.out.print( arr[k]+" "); 
//  }
//  System.out.println();
//  }
//  }
//  }