// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> A;

        for(int i=0; i<nums.size(); i++){
            A.push_back({nums[i], i});
        }

        sort(A.begin(), A.end());

        int s=0;
        int e=nums.size()-1;

        while(s < e){
            int cur = A[s].first + A[e].first;
            if(cur == target){
                return {min(A[s].second, A[e].second),
                        max(A[s].second, A[e].second)};
            }
            else if(cur > target){
                e--;
            }
            else{
                s++;
            }
        }
        return {};
    }
};