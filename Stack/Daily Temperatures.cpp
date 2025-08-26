// https://leetcode.com/problems/daily-temperatures/description/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n, 0);

        for(int i=0; i<n; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                int days = i - st.top();
                res[st.top()] = days;
                st.pop();
            }

            st.push(i);
        }

        return res;
    }
};