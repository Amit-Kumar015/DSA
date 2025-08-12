// https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int s = -1, e = -1;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for(int i=0; i<n; i++){
            if(intervals[i][0] <= e){
                s = min(intervals[i][0], s);
                e = max(intervals[i][1], e);
                ans.pop_back();
                ans.push_back({s, e});
            }
            else{
                ans.push_back(intervals[i]);
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }

        return ans;
    }
};