//Find if array contains Pythagorean Triplet or Not 
#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] >= key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }
    // for (int i = 0; i < n; i++)  
    // cout << arr[i] << " ";  
}  

bool pyTriplet(int arr[], int n) {
    //int i;
    for(int i=0;i<n;i++)
        arr[i] = arr[i] * arr[i];
InsertionSort(arr, n);
    for(int i=n-1; i>=2;i--) {
        int l= 0, r= i-1;
        while(l<r) {
            if(arr[l]+arr[r] == arr[i])
                return true;

            (arr[l] + arr[r] > arr[i]) ? r-- : l++;
        }
    }
    return false;
}

int main() {
    //int arr[]= { 3, 1, 4, 6, 5 };
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
    //int n= sizeof(arr)/sizeof(arr[0]);
    pyTriplet(arr, n) ? cout<<"Yes\n" : cout<<"No\n"; 
    }
    return 0;
}