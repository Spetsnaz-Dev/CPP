#include <bits/stdc++.h> 
using namespace std;

int findAns(vector<int>& arr, int n){
    int res = 0, curr = n;
        while(1){
            for (int i = arr.size()-1; i>=0; i--)
            {
                while(curr >= arr[i]){
                    int times = curr / arr[i];
                    curr = curr - arr[i] * times;
                    res += times;
                }
                
                if(curr == 0)   return res;
            }
        }
    return 0;
}
int main() 
{
    int n, t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        vector<int> arr;
        for(int i=0; i<12; i++)
            arr.push_back(pow(2, i));
        
        cout<<findAns(arr, n)<<endl;
    }
    return 0;
} 