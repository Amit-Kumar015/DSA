// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/description/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flips=0;
        for(int num: nums){
            if(!((num + flips)%2)){
                // ( a + b) % 2 it tells the actual value of num after all prev flips
                // a is the value of num which is inbound of 2
                // b is the no of flips it will do
                // 2 is the bound i.e it can only be 0 or 1
                // flips tells how many times flips happend before this ele

                // [1,2,3]
                // it is like (2 + 7) % 3
                // 3 tells it can only change to 0,1,2 which is map to arr
                // ans is 3 bcoz 2 changes 7 times
                // 3,1,2,3,1,2,3 and last change is 3

                flips++;
            }
        }
        return flips;
    }
};