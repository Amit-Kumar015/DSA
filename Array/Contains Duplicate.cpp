// https://leetcode.com/problems/contains-duplicate/description/

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            map<int,bool> m;
    
            for(int i=0; i<nums.size(); i++){
                if(m.find(nums[i]) != m.end()){
                    return true;
                }
                m.insert({nums[i], true});
            }
    
            return false;
        }
    };

// using sorting
class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
    
            for(int i=0; i<n-1; i++){
                if(nums[i] == nums[i+1])
                    return true;
            }
    
            return false;
        }
    };