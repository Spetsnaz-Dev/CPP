#include "bits/stdc++.h"
#define base9 1e9
#define base7 1e7
#define ll long long int
using namespace std;
int t, n;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
void printOddMatrix(int n)
{
    int k = 1;
    for(int i=0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout<<k++<<" ";
        cout<<endl;
    }
    return;
}
void printMatrix(vector<vector<int>> arr, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}
// solver functionzz
void solve(int n)
{
    if(n & 1)
        return printOddMatrix(n);

    vector<vector<int>> arr(n, vector<int> (n));
    int oddNum = 1, evenNum = 2;

    for(int i=0; i<n; i++)
    {
        int j = 0;
        if(i % 2 == 0){
            while(j < n)
            {
                arr[i][j] = oddNum;
                oddNum += 2;
                j++;
                arr[i][j] = evenNum;
                evenNum += 2;
                j++;
            }
        }
        else{
            while(j < n)
            {
                arr[i][j] = evenNum;
                evenNum += 2;
                j++;
                arr[i][j] = oddNum;
                oddNum += 2;
                j++;
            }
        }
    }
    printMatrix(arr, n);
}

int main()
{  
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    cin>>t;
    while (t--){
        cin>>n;

        // Output
        solve(n);

        cout<<"\n";
    }
    return 0;
}
