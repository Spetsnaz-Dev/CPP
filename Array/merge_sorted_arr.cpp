//More two sorted array in O(1) space
#include<iostream>
using namespace std;

void merge(int arr1[], int arr2[], int m, int n) {
    for(int i= n-1; i>=0; i--) {

        int last= arr1[m-1];
        int j;

        for(j= m-2; j>=0 && arr1[j] > arr2[i]; j--) {
            arr1[j+1] = arr1[j];
        }
        if(last > arr2[i] || j != m-2) {
            arr1[j+1] = arr2[i];
            arr2[i] = last;
        }
    }
}

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        int a, b;
        cin>>a>>b;
        int arr1[a], arr2[b];
        for (int i = 0; i < a; i++)
        {
            cin>>arr1[i];
        }
        for (int i = 0; i < b; i++)
        {
            cin>>arr2[i];
        }
        merge(arr1, arr2, a, b); 

        // cout << "After Merging \nFirst Array: "; 
        for (int i=0; i<a; i++) 
            cout << arr1[i] << " "; 
        // cout << "\nSecond Array: "; 
        for (int i=0; i<b; i++) 
            cout << arr2[i] << " "; 
    }
   return 0; 
}