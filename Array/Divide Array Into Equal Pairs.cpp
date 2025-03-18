// https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=daily-question&envId=2025-03-17

// using sort
class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            sort(nums.begin(), nums.end());
    
            for(int i=0; i<nums.size()-1; i += 2){
                if(nums[i] != nums[i+1]){
                    return false;
                }
            }
    
            return true;
        }
    };

// using map
class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int, int> m;
    
            for(int i=0; i<nums.size(); i++){
                m[nums[i]]++;
            }
    
            for(const auto& i: m){
                if(i.second % 2 != 0){
                    return false;
                }
            }
    
    
            return true;
        }
    };