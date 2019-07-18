#include<bits/stdc++.h>
using namespace std;
void nextGreaterElement(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);

    for(int i=1;i<n;i++)
    {
        // if (s.empty()) { 
        //     s.push(arr[i]); 
        //     continue; 
        // } 
        while(!s.empty() && arr[i] > s.top())
        {
            cout<<arr[i]<<" ";
            s.pop();
        }
        s.push(arr[i]);
    }
    while(!s.empty())
    {
        cout<<-1<<" ";
        s.pop();
    }
    cout<<"\n";
}
int main()
 {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        nextGreaterElement(arr, n);
    }
	return 0;
}