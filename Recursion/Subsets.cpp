// https://leetcode.com/problems/subsets/description/

class Solution {
private:
    void solve(vector<int>& nums, int index,
     vector<int> subset, vector<vector<int>>& ans){

        if(index >= nums.size()){
            ans.push_back(subset);
            return;
        }

        // exclude
        solve(nums, index+1, subset, ans);

        // include
        subset.push_back(nums[index]);
        solve(nums, index+1, subset, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;

        solve(nums, 0, subset, ans);
        return ans;
    }
};