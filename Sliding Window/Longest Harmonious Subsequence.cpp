// https://leetcode.com/problems/longest-harmonious-subsequence/description/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        if(n == 1) return 0;
        sort(nums.begin(), nums.end());

        int maxLen=0;
        int i=0, j=0;
        while(j < n){
            while(nums[j] - nums[i] > 1){
                i++;
            }

            if(nums[j] - nums[i] == 1){
                maxLen = max(maxLen, j-i+1);
            }
            j++;
        }
        
        return maxLen;
    }
};