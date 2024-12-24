// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i=1;
        vector<int> ans;

        while(i<nums.size()){
            if(nums[i] == nums[i-1]){
                ans.push_back(nums[i]);
                i+=2;
            }else{
                i++;
            }

        }
        return ans;
    }
};