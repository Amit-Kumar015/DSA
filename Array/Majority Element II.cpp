// https://leetcode.com/problems/majority-element-ii/description/

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            vector<int> ans;
            unordered_map<int, int> m;
            int freq=nums.size()/3;
    
            for(int i=0; i<nums.size(); i++){
                m[nums[i]] += 1;
            }
    
            for(auto pair: m){
                if(pair.second > freq){
                    ans.push_back(pair.first);
                }
            }
    
            return ans;
        }
    };