// https://leetcode.com/problems/k-closest-points-to-origin/description/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxH;

        for (auto& i : points) {
            int dist = i[0] * i[0] + i[1] * i[1];
            maxH.push({dist, i});

            if(maxH.size() > k) maxH.pop();
        }

        vector<vector<int>> ans;
        while(!maxH.empty()){
            ans.push_back(maxH.top().second);
            maxH.pop();
        }
        return ans;
    }
};