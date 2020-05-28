// function to find minimum number of jumps to reach end of the array
int minimumJumps(int arr[], int n){
    
    if(arr[0] == 0)
        return -1;
        
    int jumps = 1, steps = arr[0], maxReach = arr[0];
    
    for(int i=1; i<n; i++)
    {
        if(i > maxReach)
            return -1;
            
        maxReach = max(i + arr[i], maxReach);
        steps--;
        
        if(i == n-1)
            return jumps;
            
        if(steps == 0)
        {
            steps = maxReach - i;
            jumps++;
        }
    }
    return jumps;
}