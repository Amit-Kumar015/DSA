// https://leetcode.com/problems/rotate-array/description/

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int size = nums.size();
            vector<int> arr(size);
    
            for(int i=0; i<size; i++){
                arr[(i+k)%size] = nums[i];
            }
    
            nums = arr;
        }
};