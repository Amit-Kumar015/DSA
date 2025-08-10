// https://leetcode.com/problems/combinations/description/

class Solution {
    void combination(int n, int k, vector<int> &comb, vector<vector<int>> &ans, int i){
        if(comb.size() == k){
            ans.push_back(comb);
            return;
        }

        if(i > n){
            return;
        }

        comb.push_back(i);
        combination(n, k, comb, ans, i+1);
        comb.pop_back();

        combination(n, k, comb, ans, i+1);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;

        combination(n, k, comb, ans, 1);
        return ans;
    }
};