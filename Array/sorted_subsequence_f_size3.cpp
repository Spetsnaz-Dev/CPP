#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m) {

    if (m == 0) return true;
    if (n == 0) return false;

    if (v1[n - 1] == v2[m - 1]) return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}

vector<int> find3Numbers(vector<int>, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        auto res = find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and
                   isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
vector<int> find3Numbers(vector<int> arr, int n) {
    int inc[n], dec[n];
    inc[0] = -1, dec[n-1] = -1;
    
    int min = 0;
    for(int i=1;i<n;i++){
        if(arr[i] <= arr[min]){
            inc[i] = -1;
            min = i;
        }
        else
            inc[i] = min;
    }
    int max = n-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i] >= arr[max]){
            dec[i] = -1;
            // cout<<dec[i]<<" ";
            max = i;
        }
        else{
            dec[i] = max;
            // cout<<dec[i]<<" ";
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(inc[i] != -1 and dec[i] != -1){
            ans.push_back(arr[inc[i]]);
            ans.push_back(arr[i]);
            ans.push_back(arr[dec[i]]);
            return ans;
        }
    }
    return ans;
}