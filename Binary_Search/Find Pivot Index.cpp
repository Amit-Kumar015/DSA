// https://leetcode.com/problems/find-pivot-index/description/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0;

        // Calculate the total sum of the array
        for (int i = 0; i < nums.size(); i++) {
            total_sum += nums[i];
        }

        int left_sum = 0;

        // Traverse the array to find the pivot index
        for (int i = 0; i < nums.size(); i++) {
            // Check if left_sum equals right_sum
            if (left_sum == total_sum - left_sum - nums[i]) {
                return i;
            }
            left_sum += nums[i]; // Update left_sum to include current element
        }

        return -1; // No pivot index found
    }
};
