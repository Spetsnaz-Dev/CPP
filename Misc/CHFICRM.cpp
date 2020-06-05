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
// solver functionzz
string solve(vector<int>& arr)
{
    int fives = 0, tens = 0, fifteens = 0;
    for(int x : arr)
    {
        if(x == 5){
            fives++;
            continue;
        }
        else if(x == 10){
            if(fives > 0){
                fives--;
                tens++;
                continue;
            }
            else
                return "NO";
        }
        else if(x == 15){
            if(tens > 0){
                tens--;
                continue;
            }
            else if(fives >= 2){
                fives -= 2;
                fifteens++;
                continue;
            }
            else
                return "NO";
        }
    }
    return "YES";
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
        vector<int> v(n);
        for(int i=0; i<n; i++)
            cin>>v[i];

        // Output
        cout<<solve(v);

        cout<<"\n";
    }
    return 0;
}
