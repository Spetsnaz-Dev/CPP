from six.moves import input

def matcher():
  s = int(input("No of test cases"))
  while s>0:
    s-=1
    A = int(input("A:"))
    B = int(input("B:"))
    H = []
    #Input bigger array elements
    for i in range(0,A):
      temp = []
      for j in range(0,B):
        val = input("Orig_ROW:")
        temp.extend(val)
      H.append(temp)
    print(H)

    d = int(input("d:"))
    e = int(input("e:"))
    J = []
    #Calculate pattern_hash while taking input
    patternHash = 0
    #Input smaller matrix
    for i in range(0,d):
      temp = []
      for j in range(0,e):
        val = input("Pat_Row:")
        temp.extend(val)
        patternHash += int(val)
      J.append(temp)
    print(J)

    #Boundary_Case
    if A<d or B<e:
      print("Pattern cannot be searched...!!")
      continue
    
    hash = []
    col_hash = []
    col_hash_sum = 0

    for i in range(0,A-d+1):
      #Calculate hash for 1st time in a row for original matrix
      hash_row = []
      col_hash_sum = 0
      for x in range(0,e):
        temp_val = 0
        for y in range(i,i+d):
          temp_val += int(H[y][x])
        col_hash.append(temp_val)
        col_hash_sum += temp_val

      #Now store the 1st value in hash and roll for rest of the columns (rolling hash technique)
      hash_row.append(col_hash_sum)
      #Iterate for rest of the columns
      for col in range(e,B):
        temp_val = 0
        for row in range(i,i+d):
          temp_val += int(H[row][col])
        col_hash.append(temp_val)
        col_hash_sum += temp_val

        col_hash_sum -= col_hash[0]
        col_hash.pop(0)
        if col == i+d-1:
            col_hash_sum -= 4
        hash_row.append(col_hash_sum)
        print("colhashsum: ",col_hash_sum,"\n")
      hash.append(hash_row)
    
    print("patternHash: ",patternHash,"\n")
    print("HASH:\n",hash)
        


if __name__ == '__main__':
    matcher()