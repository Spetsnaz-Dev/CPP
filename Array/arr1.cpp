#include<iostream>
using namespace std;

int main() {
    int arr[] = { 1, -3, 5, 6, -3, 6, 7, -4, 9, 10 };
    int n= sizeof(arr)/sizeof(arr[0]);

    int pos=0,neg=1;
    while(1) {
        while(pos<n && arr[pos]>=0)
            pos+=2;
        while(neg<n && arr[neg]<0)
            neg+=2;

        if(pos<n && neg<n) {
            int temp= arr[pos];
            arr[pos]= arr[neg];
            arr[neg]= temp;
        } else
            break;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<", ";

    return 0;
}