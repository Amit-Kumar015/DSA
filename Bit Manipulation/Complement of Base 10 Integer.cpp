// https://leetcode.com/problems/complement-of-base-10-integer/description/

class Solution {
    public:
        int bitwiseComplement(int n) {
            if (n == 0) return 1; 
    
            int result = 0;
            int i = 0;
    
            while (n != 0) {
                int bit = n & 1;
                int complementBit = 1 - bit; // Flip 0 to 1 and 1 to 0
                result += complementBit * pow(2, i);
                i++;
                n = n >> 1;
            }
    
            return result;
        }
    };
    