#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<float> arr, int n)  
{  
    int i, j;  
    float key;
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        rer than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}  

int checkCount(vector<float> arr) {
    insertionSort(arr, arr.size());

    int n= arr.size();
    int i=0, j= n-1, count=0;

    while(i<=j) {
        if((arr[i] + arr[j]) > 3.0) {
            count++;
            j--;
        } else {
            count++;
            i++;
            j--;
        }
    }
    return count+1;
}
int main() {
    int n;
    cin>>n;
    float t;
    vector<float> arr(n);
    for(int i=0;i<n;i++)
        {
            cin>>t;
            arr.push_back(t);
        }
    cout<<checkCount(arr)<<endl;;

    return 0;
}