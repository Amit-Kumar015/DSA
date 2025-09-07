// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/?envType=daily-question&envId=2025-09-02

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) return b[1] < a[1];
            return a[0] < b[0];
        });
        int cnt = 0;

        for(int i=0; i<points.size(); i++){
            int x1 = points[i][0], y1 = points[i][1];
            int bound = INT_MIN, top = y1;

            for(int j=i+1; j<points.size(); j++){
                int x2 = points[j][0], y2 = points[j][1];

                if(y2 <= top && y2 > bound){
                    cnt++;
                    bound = y2;
                }
                if(y2 == top) top--;
            }
        }

        return cnt;
    }
};