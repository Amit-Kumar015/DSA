// https://leetcode.com/problems/happy-number/description/

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;

        while(!s.count(n)){
            s.insert(n);
            int sum=0;
            while(n != 0){
                int digit = n%10;
                sum += digit*digit;
                n /= 10;
            }

            if(sum == 1){
                return true;
            }
            n = sum;
        }

        return false;
    }
};