// https://leetcode.com/problems/combination-sum/description/

class Solution {
    void combination(vector<int>& candidates, vector<vector<int>> &ans, int &target, int i, vector<int> &com, int sum){
        if(i == candidates.size() || sum > target) return;
        if(sum == target){
            ans.push_back(com);
            return;
        }

        // include same no
        com.push_back(candidates[i]);
        combination(candidates, ans, target, i, com, sum + candidates[i]);
        com.pop_back();

        // include next no
        combination(candidates, ans, target, i+1, com, sum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> com;
        int sum=0;

        combination(candidates, ans, target, 0, com, sum);
        return ans;
    }
};