// https://leetcode.com/problems/make-array-non-decreasing/description/?envType=problem-list-v2&envId=monotonic-stack

class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int maxEle = INT_MIN;
        int size = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= maxEle){
                size++;
                maxEle = nums[i];
            }
        }
        return size;
    }
};