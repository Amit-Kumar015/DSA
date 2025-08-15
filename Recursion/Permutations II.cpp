// https://leetcode.com/problems/permutations-ii/description/

class Solution {
    unordered_map<int, int> m;
    vector<vector<int>> res;
public:
    void permute(vector<int>& nums, vector<int>& perm){
        if(perm.size() == nums.size()){
            res.push_back(perm);
            return;
        }

        for(auto& [key, value]: m){
            if(value > 0){
                perm.push_back(key);
                value--;
                permute(nums, perm);

                // backtracking
                perm.pop_back();
                value++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int num: nums){
            m[num]++;
        }
        vector<int> perm;

        permute(nums, perm);
        return res;
    }
};