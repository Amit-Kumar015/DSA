// https://leetcode.com/problems/number-of-1-bits/description/

class Solution {
    public:
        // More optimized
        int hammingWeight(int n) {
            int cnt=0;  // count of set bit
            while(n>0){  // iterate until all bits are traversed
                ++cnt;
                n=n&(n-1); // change the first set bit from right to 0
            }
            return cnt;
        }

        int cnt=0;  // count of set bit
        while(n>0){  // iterate until all bits are traversed
            if((n&1)>0) // check the parity of first bit from right
                ++cnt;
            n=n>>1; //n=n/2, shift one bit to right
        }
        return cnt;
    };