int Solution::solve(int A) {
    int n = A;
    int count = 0;
    int index;
    for (int i = 31; i >= 0; i--) {
        int b = A & (1 << i);
        if (b != 0) {
            index = i;
            break;
        }
    }
    // cout<<index<<endl;
    for (int i = 0; i <= index; i++) {
        int b = n & (1 << i);
        if (b == 0) {
            int a = n / (1 << (i + 1));
            a = ((a % mod)((1 << i) % mod)) % mod;
            count = ((count % mod) + (a % mod)) % mod;
        } else {
            int a = n / (1 << (i + 1));
            a = ((a % mod)((1 << i) % mod)) % mod;
            count = ((count % mod) + (a % mod)) % mod;
            int k = n % (1 << (i + 1)) - (1 << i) + 1;
            count = ((count % mod) + (k % mod)) % mod;

        }
    }
    // cout<<index<<endl;
    return count % mod;

}