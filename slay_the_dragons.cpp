#include<bits/stdc++.h>
using namespace std;
void slayDragons(int arr[], int n, int t) {
    int dragons = arr[0];
    int steps=0;
    int i=1;
    sort(arr, arr+n);
    while(i<n && steps<=t) {
        if(arr[i+1] > arr[i]) {
            dragons += arr[i++];
            steps++;
        }
        while(i>=n-2 && arr[i+1] < arr[i] && steps<=t) {
            dragons += arr[i];
            i -=1;
            steps++;
        }
    }
    cout<<dragons<<"\n";
}
int main() {
    int n;
    cin>>n;
    int t;
    cin>>t;
    int arr[n];
    for(int i=0;i<n;i++) 
        cin>>arr[i];
    slayDragons(arr, n, t);

    return 0;
}