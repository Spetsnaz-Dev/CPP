#include<bits/stdc++.h>
using namespace std;
void maxSubarrayElement(int arr[], int n, int k)
{
    deque<int> dq;

    int i;
    //process first window of size k
    for(i = 0; i < k; i++){
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    //process rest k+1 to n-1 elements
    for(; i < n; i++)
    {
        // front->rear element is the max element
        cout<<arr[dq.front()]<<" ";

        //remove front element because this is the leftmost element
        while(!dq.empty() && dq.front() <= i-k)
            dq.pop_front();
        // add new element
        while(!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<"\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        maxSubarrayElement(arr, n, k);
        }
	return 0;
}