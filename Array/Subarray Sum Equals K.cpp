// https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> prefixSum;
            prefixSum[0]++;
    
            int sum=0;
            int res=0;
    
            for(int i=0; i<nums.size(); i++){
                sum += nums[i];
                int diff = sum - k;
                res += prefixSum[diff];
                prefixSum[sum]++;
            }
    
            return res;
        }
    };