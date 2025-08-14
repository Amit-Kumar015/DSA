// https://leetcode.com/problems/non-overlapping-intervals/description/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        sort(intervals.begin(), intervals.end());
        int lastEnd = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start < lastEnd){
                cnt++;
                lastEnd = min(lastEnd, end);
            }
            else{
                lastEnd = end;
            }
        }

        return cnt;
    }
};