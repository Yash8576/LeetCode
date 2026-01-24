class Solution {
public:
    int reverseBits(int n) {
        int i =1;
        int result = 0;
        while(i<=32){
            int bit = n & 1;
            result = result<<1 | bit;
            n = n>>1;
        }
        return result;
    }
};