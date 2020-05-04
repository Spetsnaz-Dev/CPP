#include<bits/stdc++.h>
using namespace std;
void findMedian(int arr[], int n)
{
    // For storing the smaller half elements
    priority_queue<int> maxHeap;  
    // For storing upper half elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // output median of first element
    int med = 0;
    maxHeap.push(arr[0]);
    med = arr[0];
    cout<<arr[0]<<"\n";

    // remaining elements
    int curr, temp;
    for(size_t i=1; i<n; i++)
    {
        curr = arr[i];

        if(maxHeap.size() > minHeap.size()){
            if(curr < med){
                temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
                maxHeap.push(curr);
            }
            else{
                minHeap.push(curr);
            }
            med = (maxHeap.top() + minHeap.top()) / 2;
        }
        else if(maxHeap.size() < minHeap.size()){
            if(curr > med){
                temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
                minHeap.push(curr);
            }
            else{
                maxHeap.push(curr);
            }
            med = (maxHeap.top() + minHeap.top()) / 2;
        }
        else if(maxHeap.size() == minHeap.size()){
            if(curr < med){
                maxHeap.push(curr);
                med = maxHeap.top();
            }
            else{
                minHeap.push(curr);
                med = minHeap.top();
            }
        }
        cout<<med<<"\n";
    }
}
int main()
 {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    findMedian(arr, n);
	
    return 0;
}