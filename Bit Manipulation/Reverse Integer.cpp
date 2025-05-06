// https://leetcode.com/problems/reverse-integer/description/

class Solution {
    public:
        int reverse(int x) {
            int reverse=0;
            while(x !=0){
                int digit = x % 10;
    
                // INT_MAX = 2147483647, INT_MIN = -2147483648
                if(reverse > INT_MAX/10 || (reverse == INT_MAX && digit > 7)) return 0;
                if(reverse < INT_MIN/10 || (reverse == INT_MAX && digit > -8)) return 0;
    
                reverse = reverse*10 + digit;
                x /= 10;
            }
    
            return reverse;
        }
    };