class Solution {
public:
    int findComplement(int num) {
        long t, dec = 0, base = 1;
        
        while(num)
        {
            t = (num & 1);  //get lsb
            // cout<<t<<" ";
            t = t ^ 1;      //xor to get bit flipped
            num >>= 1;
            dec += base * t;    //our new decimal val
            base = base * 2;    
        }
        return dec;
    }
};