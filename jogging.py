l,h = map(int,input().split())
k = int(input())
lst=[]

for i in range(l,h+1):
    lst.append(i)

e =[]
o=[]

for i in lst:
    if i%2==0:
        e.append(i)
    else:
        o.append(i)

el = len(e)
ol = len(o)
res = 0.5*((ol+el)*k + (el-ol)*k)

print(int(res))
