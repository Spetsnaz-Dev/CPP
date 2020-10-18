#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
#define ull unsigned long long int
#define pb push_back

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

void print(vector<int> arr){
    for(int i : arr)
        cout<<i<<" ";
    cout<<"\n";
}

void findAND(vector<int> arr){
    cout<<"-----------------------------\n";
    for(int i=0; i+1<arr.size(); i+=2){
        int res = arr[i] & arr[i+1];
        cout<<arr[i] <<" & "<<arr[i+1]<<" -> "<<res<<"\n";
    }
    cout<<"-----------------------------\n";
}
void generateArr(vector<int>& arr){
    for(int i=3; i+1<arr.size(); i++){
        bool ok = ceil(log2(arr[i])) == floor(log2(arr[i]));
        if(ok){
            swap(arr[i+1], arr[i]);
            i++;
        }
    }
}
// solver functionzz
void solve(int n){
    if(n == 1){
        cout<<"1\n";
        return;
    }
    bool ok = ceil(log2(n)) == floor(log2(n));
    if(ok){
        cout<<-1<<"\n";
        return;
    }
    if(n == 3){
        cout<<"2 3 1\n";
        return;
    }   

    vector<int> arr;
    for(int i=1; i<=n; i++)
        arr.pb(i);
    arr[0] = 2, arr[1] = 3, arr[2] = 1;
    // print(arr);
    generateArr(arr);
    // findAND(arr);
    print(arr);
}

int main()
{
    // Input
    int t,n;
    cin>>t;
    while (t--){
        cin>>n;
        // Output
        solve(n);
    }
    return 0;
}
