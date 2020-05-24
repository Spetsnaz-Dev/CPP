bool compare(struct val a, struct val b)
{
    return a.first <= b.first;
}
int maxChainLen(struct val p[],int n)
{
    vector<int> dp(n, 1);
    
    sort(p, p+n, compare);  // Sort and do operation like 2-pointer algo
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++)
            if(p[i].first > p[j].second and dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    }
    // int res = *max_element(dp.begin(), dp.end());
    return *max_element(dp.begin(), dp.end());;
}