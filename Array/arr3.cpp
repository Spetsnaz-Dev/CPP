//K'th largest/smallest element in an unsorted array

#include<iostream>
using namespace std;

void swp(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a]= arr[b];
    arr[b]= temp;
}

int part(int a[], int l, int r) {
    int x= a[r];
    int i=l-1;
        for(int j=l;j<r;j++) {
            if(a[j]<= x)
                swp(a, ++i, j);
        }
        swp(a, ++i, r);
    return i;
}

int rearrange(int arr[], int l, int r, int k) {
    while(l<=r) {
        int piv= part(arr, l, r);

        if(piv == k-1)
            return arr[piv];
        else if(piv< k-1)
            l= piv+1;
        else
            r= piv-1;
    }
    return -1;
}

int main() {
    int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
    int n= sizeof(arr)/sizeof(arr[0]);

    int k=3;
    cout<<rearrange(arr, 0, n-1, k);

    return 0;
}