input1 = str(input())
odd = 0
even = 0
res = input1.split()
for ele in res:
    sum = 0
    for c in ele:
        sum = sum + ord(c)
    # print(sum)
    if (sum % 2) == 0:
        even = even + 1
    else:
        odd = odd + 1

ans = "odd" + str(odd) + "even" + str(even)
# return ans
print(ans)
