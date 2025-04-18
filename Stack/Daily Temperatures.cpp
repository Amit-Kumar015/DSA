// https://leetcode.com/problems/daily-temperatures/description/

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            int n=temperatures.size();
            vector<int> ans(n, 0);
            stack<pair<int, int>> stack; // pair: {temp, index}
    
            for(int i=0; i<n; i++){
                int t = temperatures[i];
    
                while(!stack.empty() && t > stack.top().first){
                    auto pair = stack.top();
                    ans[pair.second] = i - pair.second;
                    stack.pop();
                }
    
                stack.push({t, i});
            }
    
            return ans;
        }
    };