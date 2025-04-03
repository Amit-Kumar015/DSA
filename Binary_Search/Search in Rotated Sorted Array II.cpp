// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int l=0, r=nums.size()-1;
    
            while(l<=r){
                int mid = l+(r-l)/2;
    
                if(nums[mid] == target){
                    return true;
                }
    
                if(nums[l] < nums[mid]){
                    if(target >= nums[l] && target < nums[mid]){
                        r=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
                else if(nums[l] > nums[mid]){
                    if(target <= nums[r] && target > nums[mid]){
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
                else{
                    l++;
                }
            }
    
            return false;
        }
    };