// Max Sum Circular Subarray
class Solution {
public:
    int kadanes(vector<int> arr){
        int curr = 0, meh = INT_MIN;
            for(int pos=0; pos<arr.size(); pos++)
            {
                // int pos = (i + k) % n;
                curr += arr[pos];
                
                if(curr < arr[pos])
                    curr = arr[pos];
                
                if(meh < curr)
                    meh = curr;
            }
        return meh;
    }
    int maxSubarraySumCircular(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 1)
            return arr[0];
        
        int res = INT_MIN, sum = 0;
        int maxKadane = kadanes(arr);
        // int t = *max_element(arr.begin(), arr.end());
        int t = INT_MIN;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            t = max(t, arr[i]);
            arr[i] = -arr[i];   //invert for wrap
        }
        
        res = sum + kadanes(arr);
        
        if(t < 0)
            return t;
        
        if(res > maxKadane)
            return res;
        else
            return maxKadane;
    }
};