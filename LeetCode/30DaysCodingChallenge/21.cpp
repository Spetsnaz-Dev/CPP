int rangeBitwiseAnd(int a, int b) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int count = 0;
        while(a != b){
            a >>= 1;
            b >>= 1;
            count++;
        }
        return a<<=count;
    }