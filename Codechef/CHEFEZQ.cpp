    #include "bits/stdc++.h"
    #define ll long long int
    #define pb push_back
    using namespace std;

    static int speedUp=[](){
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return 0;
    }();

    // solver functionzz
    ll solve(vector<int>& arr, int k){
        if(arr.size() == 1) return arr[0]/k + 1;
        ll rem = 0, res = 0;

        for(int i=0; i<arr.size(); i++){
            rem += arr[i] - k;
            res++;
            if(rem < 0)
                return res;
        }
        return res + rem/k + 1;
    }

    int main()
    {
        // Input
        int t,n,k;
        cin>>t;
        while (t--){
            cin>>n>>k;
            vector<int> v(n);
            for (size_t i = 0; i < n; i++){cin>>v[i];}

            // Output
            cout<<solve(v, k);
            cout<<"\n";
        }
        return 0;
    }
