#include<bits/stdc++.h>
#define N 105
using namespace std;

int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}
int res[N*N];
int *mergeKArrays(int arr[][N], int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            pq.push(arr[i][j]);
        }
    }
    int ele, i = 0;
    while(!pq.empty()){
        ele = pq.top();
        res[i] = ele;
        //cout<<res[i]<<" ";
        pq.pop();
        ++i;
    }
    return res;
}