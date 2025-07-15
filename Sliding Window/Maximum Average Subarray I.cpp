// https://leetcode.com/problems/maximum-average-subarray-i/description/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        double currSum=0, maxSum=0;
        while(i < k){
            currSum += nums[i];
            i++;
        }
        maxSum = currSum;
        
        for(i=k; i<nums.size(); i++){
            currSum += nums[i];
            currSum -= nums[i-k];
            maxSum = max(maxSum, currSum);
        }

        return maxSum/k;
    }
};