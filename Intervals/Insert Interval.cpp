// https://leetcode.com/problems/insert-interval/description/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int s = newInterval[0];
        int e = newInterval[1];
        vector<vector<int>> ans;
        bool inserted = false;

        for(int i=0; i<intervals.size(); i++){
            if(s < intervals[i][0] && e > intervals[i][1]){
                continue;
            }
            else if((s >= intervals[i][0] && s <= intervals[i][1]) || 
            (e >= intervals[i][0] && e <= intervals[i][1])){
                s = min(intervals[i][0], s);
                e = max(intervals[i][1], e);
            }
            else if(e < intervals[i][0] && !inserted){
                ans.push_back({s, e});
                ans.push_back(intervals[i]);
                inserted = true;
            }
            else{
                ans.push_back(intervals[i]);
            }
        }

        if(!inserted){
            ans.push_back({s, e});
        }

        return ans;
    }
};

