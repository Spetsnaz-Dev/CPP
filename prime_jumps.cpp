#include<bits/stdc++.h>
using namespace std;

int findJumps(vector<int> arr) {
    int n= arr.size();
    int flag=0, prime = 0, res=1, temp= 0, max_length= 0;
    vector<int> primes;
    sort(arr.begin(), arr.end());
    for(int i=2;i<n;i++) {
        for(int j=0;j<n/2;j++) {
            if(arr[i] % j != 0)
                flag=1; prime = i;
                res= arr[i];
        
        if(flag== 1) {
            temp=0;
            for(int i=0;i<n;i++) {
                if(res < arr[n-1]) {
                    res= res* prime;
                    temp++;
                }
            }
                if(max_length < temp)
                    max_length = temp;
            }
        }
    }
    return max_length+1;
}
int main() {
    int n;
    cin>>n;
    vector<int> arr;
    int t;
    for(int i=0;i<n;i++)
        {
            cin>>t;
            arr.push_back(t);
        }
        cout<<findJumps(arr)<<endl;
        return 0;
}