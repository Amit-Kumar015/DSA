// https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(auto& interval: intervals){
            int start = interval[0];
            int end = interval[1];
            int lastEnd = ans.back()[1];

            if(start <= lastEnd){
                ans.back()[1] = max(lastEnd, end);
            }
            else{
                ans.push_back(interval);
            }
        }

        return ans;
    }
};