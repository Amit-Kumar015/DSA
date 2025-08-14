// https://leetcode.com/problems/insert-interval/description/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int s = newInterval[0];
        int e = newInterval[1];
        int n = intervals.size();
        vector<vector<int>> res;

        for(int i=0; i<n; i++){
            if(intervals[i][0] > e){
                res.push_back({s, e});
                copy(intervals.begin() + i, intervals.end(), back_inserter(res));
                return res;
            }
            else if(intervals[i][1] < s){
                res.push_back(intervals[i]);
            }
            else{
                s = min(intervals[i][0], s);
                e = max(intervals[i][1], e);
            }
        }

        res.push_back({s, e});
        return res;
    }
};

