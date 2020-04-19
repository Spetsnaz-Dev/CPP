// Method 1
int search(vector<int>& arr, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = arr.size();
        
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = (low+high)/2;
            
            if(arr[mid] == target)
                return mid;
            
            if(arr[low] <= arr[mid]) {
                if(arr[mid] >= target and arr[low] <= target)
                    high = mid-1;
                else
                    low = mid+1;
            }
            else {
                if(arr[mid] <= target and arr[high] >= target)
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return -1;
    }