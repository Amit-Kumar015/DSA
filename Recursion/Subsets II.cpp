// https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>> &ans, vector<int> &subset, int i){
        if(i == nums.size()){
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(nums, ans, subset, i+1);
        subset.pop_back();

        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }

        backtrack(nums, ans, subset, i+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        backtrack(nums, ans, subset, 0);

        return ans;
    }
};