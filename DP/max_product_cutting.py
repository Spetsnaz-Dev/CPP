# def maxProd(n):
#     if(n <= 1):
#         return 0
#     if(n == 2):
#         return 1
#     dp = [0] * (n+1)
#     for i in range(1, n+1):
#         max_val = 0
#         upper_limit = i//2 + 1
#         for j in range(1, upper_limit):
#             max_val = max(max_val, (i-j)*j, dp[i-j]*j)
#         dp[i] = max_val % 1000000007
#     return dp[n]

# EFFICIENT METHOD
def maxProd(n):
    if n==2 or n==3:
        return n-1
    
    res = 1
    while (n > 4):
        n -= 3
        res *= 3
    # remainder finally will be 2 or 3 or 4
    return (n*res) % 1000000007

t = int(input())
for T in range(t):
    n = int(input())
    print(maxProd(n))
