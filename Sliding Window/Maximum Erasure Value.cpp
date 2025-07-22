// https://leetcode.com/problems/maximum-erasure-value/description/?envType=daily-question&envId=2025-07-22

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int size = nums.size();
        int l=0, r=0, sum=0, maxSum=0;

        while(r < size){
            if(s.contains(nums[r])){
                maxSum = max(maxSum, sum);
                while(nums[l] != nums[r]){
                    s.erase(nums[l]);
                    sum -= nums[l];
                    l++;
                }
                l++;
                r++;
                continue;
            }

            s.insert(nums[r]);
            sum += nums[r];
            r++;
        }

        maxSum = max(maxSum, sum);
        return maxSum;
    }
};