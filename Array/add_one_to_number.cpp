vector<int> Solution::plusOne(vector<int> &A) {
    //reverse(A.begin(), A.end());
    int n = A.size();
    
    A[n-1] += 1;
    int carry = A[n-1]/10;
    A[n-1] = A[n-1]%10;
    
    for(int i=n-2;i>=0;i--)
    {
        if(carry == 1)
        {
            A[i] += 1;
            carry = A[i]/10;
            A[i] = A[i]%10;
        }
    }
    if(carry >0)
        A.insert(A.begin(), 1); //Insert element at beginning of vector
    while(A[0] == 0)
        A.erase(A.begin());     //Remove trailing zeroes
        
    return A;
}