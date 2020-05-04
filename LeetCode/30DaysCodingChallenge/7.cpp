#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int countElements(vector<int> arr, int n)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    int n = arr.size();
    if(n == 0 or n==1)
        return 0;
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    
    int ele, count = 0;
    for(int i=0; i<n; i++) {
        ele = arr[i] + 1;
        if(mp.find(ele) != mp.end())
            count++;
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    cout<< countElements(v, n)<<"\n";

    return 0;
}