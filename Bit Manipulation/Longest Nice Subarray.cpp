// https://leetcode.com/problems/longest-nice-subarray/description/?envType=daily-question&envId=2025-03-18

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int maxLen=0;
            int i=0; // left side of window
            int bitMask=0;
    
            for(int j=0; j<nums.size(); j++){ // right side of window
                while((bitMask & nums[j]) != 0){
                    bitMask ^= nums[i]; // removing leftmost element bitmask
                    i++;
                }
    
                bitMask |= nums[j]; // adding new element
                maxLen = max(maxLen, j-i+1); // update max size
            }
    
            return maxLen;
        }
    };