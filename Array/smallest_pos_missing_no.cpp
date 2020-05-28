// Find smallest positive missing number in an array
int findMissing(int arr[], int n) { 
    bool one = false;
    for(int i=0; i<n; i++){
        if(arr[i] == 1)
            one = true;
        else if(arr[i] <= 0 or arr[i] >= n)
            arr[i] = 1;
        }
    if(!one)
        return 1;
    
    for(int i=0; i<n; i++)
    {
        int curr = abs(arr[i]);
        arr[curr] = -abs(arr[curr]);
    }
    
    for(int i=1; i<n; i++)
        if(arr[i] > 0)
            return i;
            
    return n+1;
}