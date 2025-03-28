// https://leetcode.com/problems/concatenation-of-array/description/

class Solution {
    public:
        vector<int> getConcatenation(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans(2 * n);
    
            for(int i=0; i<n; i++){
                ans[i] = ans[i+n] = nums[i];
            }
    
            return ans;
        }
    };

// change to original array

class Solution {
    public:
        vector<int> getConcatenation(vector<int>& nums) {
            int n = nums.size();
    
            for(int i=0; i<n; i++){
                nums.push_back(nums[i]);
            }
    
            return nums;
        }
    };