//Find no of inversions in an array
#include<iostream>
using namespace std;
typedef long long int ll;

ll merge(ll arr[], ll temp[], ll low, ll mid, ll high)
{
    ll i,j,k, count = 0;
    i = low;    j = mid;    k = low;
    while ((i <= mid-1) && (j <= high))
    {
        if(arr[i] > arr[j]){
            temp[k++] = arr[j++];
            count += mid - i;
        }
        else {
            temp[k++] = arr[i++];
        }
    }
    while(i <= mid-1)
        temp[k++] = arr[i++];
    while(j <= high)
        temp[k++] = arr[j++];
    for(ll i=low;i<=high;i++)
        arr[i] = temp[i];
        
    return count;
}
ll mergeSort(ll arr[], ll temp[], ll low, ll high)
{
    ll mid, inv_count = 0;
    if(low < high){
        mid = (low + high) / 2;

        inv_count += mergeSort(arr, temp, low, mid);
        inv_count += mergeSort(arr, temp, mid+1, high);

        inv_count += merge(arr, temp, low, mid+1, high);
    }
    return inv_count;
}
ll countInversions(ll arr[], ll size){
    ll temp[size] = {0};
    return mergeSort(arr, temp, 0, size-1);
}
int main()
 {
	ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        cout<<countInversions(arr, n)<<"\n";       
        }
	return 0;
}
// ll mergeArr(ll arr[], ll temp[], ll left, ll mid, ll right) {
//     ll i=left;    //for left Sub-Array
//     ll j=mid;    //for Right Sub-Array
//     ll k=left;    //for new array

//     ll new_count=0;
//     while(i<=mid-1 && j<=right) {
//         if(arr[i] <= arr[j])
//             temp[k++] = arr[i++];
//         else {
//             temp[k++] = arr[j++];
//             new_count+= (mid-i);
//         }
//     }
//     while(i<=mid-1)
//         temp[k++]= arr[i++];

//     while(j<=right)
//         temp[k++] = arr[j++];
    
//     for(ll i=left; i<= right; i++)
//         arr[i] = temp[i];

//     return new_count;
// }

// ll mergeSorter(ll arr[], ll temp[], ll left, ll right) {
//     ll mid, count=0;
//     if(left< right) {
//         mid= (left+right)/2;
//         count= mergeSorter(arr, temp, left, mid);
//         count+= mergeSorter(arr, temp, mid+1, right);
//         count+= mergeArr(arr, temp, left, mid+1, right);
//     }
//     return count;
// }

// ll findInversions(ll arr[], ll n) {
//     ll temp[n*2];
//     return mergeSorter(arr, temp, 0, n-1);
// }

// ll main() {
//     ll arr[]= {2, 4, 1, 3, 5};
//     cout<<"No of inversions are - "<< findInversions(arr, 5) <<"\n";

//     return 0;
// }