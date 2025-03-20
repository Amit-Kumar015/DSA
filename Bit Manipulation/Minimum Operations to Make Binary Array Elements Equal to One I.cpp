// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/?envType=daily-question&envId=2025-03-19

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int count=0;
            int i=0;
    
            while(i<nums.size()-2){
                if(nums[i] == 0){
                    //flip
                    nums[i] = !nums[i];
                    nums[i+1] = !nums[i+1];
                    nums[i+2] = !nums[i+2]; 
                    count++;
                }
                
                i++;
            }
    
            int ans=1;
            for(auto num: nums){
                ans &= num;
            }
    
            return ans ? count : -1;
        }
    };