// https://leetcode.com/problems/number-of-unique-xor-triplets-ii/description/

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st, s;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                st.insert(nums[i] ^ nums[j]);
            }
        }

        for (auto num : st) {
            for (auto x : nums) {     
                s.insert(num ^ x); 
            }
        }
        return s.size();
    }
};