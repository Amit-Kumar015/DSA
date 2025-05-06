// https://leetcode.com/problems/power-of-two/description/

class Solution {
    public:
        bool isPowerOfTwo(int n) {
            return n > 0 && (n & (n - 1)) == 0;
        }
    };


    class Solution {
        public:
            bool isPowerOfTwo(int n) {
                for(int i=0; i<31; i++){
                    if(n == (1 << i)) return true;
                }
        
                return false;
            }
        };