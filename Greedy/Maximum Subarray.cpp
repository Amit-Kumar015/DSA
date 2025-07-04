// https://leetcode.com/problems/maximum-subarray/description/

// kadane algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0], curSum = 0;
        for(int num: nums){
            if(curSum < 0){
                curSum = 0;
            }

            curSum += num;
            maxSub = max(maxSub, curSum);
        }
        return maxSub;
    }
};

// binary search
class Solution {
private:
    int dfs(vector<int>& nums, int l, int r){
        if(l > r){
            return INT_MIN;
        }
        int m = (l+r)/2;

        int curSum = 0, leftSum = 0, rightSum = 0;
        for(int i=m-1; i>=l; i--){
            curSum += nums[i];
            leftSum = max(leftSum, curSum);
        }

        curSum = 0;
        for(int i=m+1; i<=r; i++){
            curSum += nums[i];
            rightSum = max(rightSum, curSum);
        }

        return max(dfs(nums, l, m-1), max(dfs(nums, m+1, r), leftSum +     nums[m] + rightSum));
    }
public:
    int maxSubArray(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};