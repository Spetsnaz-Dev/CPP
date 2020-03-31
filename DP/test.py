def getDecision(m,n):
    v = []
    if(m == n): 
        return v

    if(m > n): 
        while(m != n):
            v.append("eat")
            m -= 1
        return v
  
    # n is greater and n is odd 
    if(n % 2 == 1): 
        v.append("eat")
        getDecision(m, n + 1) 
  
    # n is even 
    else:
        v.append("overflow")
        getDecision(m, n // 2) 

t=int(input())
for _ in range(0,t):
    m,n=list(map(int,input().split()))
    a=getDecision(m,n)
    print(*a[::-1])