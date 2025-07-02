// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

class Solution {
private:
    int dfs(vector<int>& nums, int i, int total){
        if(i == nums.size()){
            return total;
        }

        // include num[i] in total + exclude nums[i] in total
        return dfs(nums, i+1, total^nums[i]) + dfs(nums, i+1, total);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};