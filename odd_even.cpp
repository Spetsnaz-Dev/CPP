#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mod 1000000007
using namespace std;

ll powerofel(long long a, ll b) {
    if (a == 0)
        return 1;
    long long ans = 1;
    a = a % mod;
    while (b > 0) {
        if (b & 1)
            ans = (ans * a) % mod;

        b = b >> 1;
        a = (a * a) % mod;
    }
    return ans;
}

ll perm(ll low, ll high, ll k) {

    vector<ll> fact(k+1);
    fact[0] = 1;

    for (ll i = 0; i <= k; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    long long ans = 0, tot = high - low, even = tot / 2, odd = even;
    if (tot % 2 == 1) {
        if (low % 2 == 1)
            odd += 1;
        else
            even += 1;
    }
    for (ll i = 0; i <= k; i += 2) {
        ll c = ((fact[k] * powerofel(fact[i], mod - 2)) % mod * powerofel(fact[k - i], mod - 2)) % mod;
        ans = (ans + ((c * powerofel(odd, i)) % mod * powerofel(even, k - i)) % mod) % mod;
    }
    return ans % mod;
}

int main() {
    ll low, high, k;
    cin >> low >> high >> k;
    cout << perm(low, high, k);
    return 0;
}