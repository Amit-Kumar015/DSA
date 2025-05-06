// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/

class Solution {
    public:
        int subtractProductAndSum(int n) {
            vector<int> digits;
    
            int digit=0;
            while(n != 0){
                digit = n%10;
                digits.push_back(digit);
                n /=10;
            }
    
            int sum=0;
            int prod=1;
            for(int digit: digits){
                sum += digit;
                prod *= digit;
            }
    
            return prod - sum;
        }
    };