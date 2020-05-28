// function to count ways to reach mth stair
// order doesnt matter

// Method 1
long long countWays(int m){
    // No of ways by jumping with 2 and + 1 using 1
    // because 1 will always have 1 way to go to any number
    return m/2 + 1;
}

// Method 2
long long countWays(int m){
    vector<int> v2(m+1);
    
    v2[0] = 1, v2[1] = 1;
    for(int i=2; i<=m; i++){
        v2[i] = v2[i-2] + 1;
    }
    return v2[m];
}