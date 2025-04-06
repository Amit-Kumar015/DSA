// https://leetcode.com/problems/rotate-array/description/

class Solution {
    private:
        void reverse(vector<int>& nums, int s, int e){
            while(s<e){
                swap(nums[s], nums[e]);
                s++;
                e--;
            }
        }
    
    public:
        void rotate(vector<int>& nums, int k) {
            int n=nums.size();
            k %= n;
    
            reverse(nums, 0, n-1);
            reverse(nums, 0, k-1);
            reverse(nums, k, n-1);
        }
    };
    

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

