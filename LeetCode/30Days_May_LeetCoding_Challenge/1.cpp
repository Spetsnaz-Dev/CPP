int firstBadVersion(int n) {
        long l = 1, h = n, mid = 1;
        
        while(l <= h) {
            mid = (l+h)/2;
            
            if(l == h)
                break;
            
            bool ans = isBadVersion(mid);
            
            if(ans == true){
                h = mid;
            }
            else if(ans == false) {
                l = mid+1;
            }
        }
        return mid;
    }