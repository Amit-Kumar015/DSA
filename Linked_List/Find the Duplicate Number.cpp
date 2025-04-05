// https://leetcode.com/problems/find-the-duplicate-number/description/

// negative masking
class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            for(int i=0; i<nums.size(); i++){
                int idx = abs(nums[i]) - 1;
    
                if(nums[idx] < 0){
                    return abs(nums[i]);
                }
    
                nums[idx] *= -1;
            }
    
            return -1;
        }
    };

// slow fast pointer
class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int slow=0, fast=0;
    
            while(true){
                slow = nums[slow];
                fast = nums[nums[fast]];
    
                if(slow == fast){
                    break;
                }
            }
    
            int slow2=0;
            while(true){
                slow2 = nums[slow2];
                slow = nums[slow];
    
                if(slow == slow2){
                    return slow;
                }
            }
        }
    };