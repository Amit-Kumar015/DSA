// https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
    void dfs(vector<int>& candidates, int &target, vector<vector<int>> &ans, 
    vector<int> &comb, int sum, int i){
        if(sum == target){
            ans.push_back(comb);
            return;
        }
        if(i == candidates.size() || sum > target) return;

        // include
        comb.push_back(candidates[i]);
        dfs(candidates, target, ans, comb, sum+candidates[i], i+1);
        comb.pop_back();

        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]){
            i++;
        }

        // exclude
        dfs(candidates, target, ans, comb, sum, i+1);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());

        dfs(candidates, target, ans, comb, 0, 0);
        return ans;
    }
};