int max_sum(int arr[],int n)
{
    int maxx = 0, sum = 0, currVal = 0;
    
    //for first window
    for(int i=0; i<n; i++){
        sum += arr[i];
        currVal += i*arr[i];
    }
    maxx = currVal;
    //for rest of the rotation window
    for(int i=1; i<n; i++){
        int nextVal = currVal + (n-1)*arr[i-1] - (sum - arr[i-1]);
        
        currVal = nextVal;
        maxx = max(currVal, maxx);
    }
    return maxx;
}