// https://leetcode.com/problems/number-of-unique-xor-triplets-i/description/

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;

        if(n < 3) return n;

        while(n > 0){
            n >>= 1;
            cnt++;
        }
        return pow(2, cnt);
    }
};