#include "bits/stdc++.h"
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    int n = stones.size();

    if(n == 0)  // Edge Case
        return 0;
    if(n == 1)
        return stones[0];

    priority_queue<int> pq;
    for(int i=0; i<n; i++)
        pq.push(stones[i]);
    
    while (pq.size() > 1)
    {
        for(int i=0; i<pq.size(); i++){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            
            if(x != y){
                y = y - x;
                pq.push(y);
            }
        }
    }
    return pq.size() == 0 ? 0 : pq.top();
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<lastStoneWeight(arr);

    return 0;
}