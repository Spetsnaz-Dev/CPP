#define p 1000000007
int nCrModp(int n, int k)
{
    vector<vector<int>> C(n+1, vector<int> (k+1));
    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else            
                C[i][j] = (C[i - 1][j - 1] % p + C[i - 1][j] % p) % p;
        }
    }
    return C[n][k];
}