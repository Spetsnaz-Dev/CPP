def maxLoot(loot,N):
    if(N==1):
        return loot[0]
    if(N==2):
        return max(loot[0],loot[1])
    dp = [0]*N
    dp[0]=loot[0]
    dp[1]=max(loot[0],loot[1])
    for i in range(2,N):
        dp[i] = max(dp[i-2]+loot[i],dp[i-1])
    return dp[N-1]

T = int(input())
for t in range(T):
    N = int(input())
    loot = list(map(int,input().split()))
    print(maxLoot(loot,N))