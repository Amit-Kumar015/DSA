// https://leetcode.com/problems/next-greater-element-i/description/?envType=problem-list-v2&envId=monotonic-stack

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;
        vector<int> res;

        for(int i=0; i<nums2.size(); i++){
            while(!st.empty() && st.top() < nums2[i]){
                nextGreater[st.top()] = nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        }

        while(!st.empty()){
            nextGreater[st.top()] = -1;
            st.pop();
        }

        for(int i: nums1){
            res.push_back(nextGreater[i]);
        }
        return res;
    }
};