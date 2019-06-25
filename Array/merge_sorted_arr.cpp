
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
    int arr1[] = {1, 5, 9, 10, 15, 20}; 
    int arr2[] = {2, 3, 8, 13}; 

    int m = sizeof(arr1)/sizeof(arr1[0]); 
    int n = sizeof(arr2)/sizeof(arr2[0]); 
    merge(arr1, arr2, m, n); 

    cout << "After Merging \nFirst Array: "; 
    for (int i=0; i<m; i++) 
        cout << arr1[i] << " "; 
    cout << "\nSecond Array: "; 
    for (int i=0; i<n; i++) 
        cout << arr2[i] << " "; 
   return 0; 
}