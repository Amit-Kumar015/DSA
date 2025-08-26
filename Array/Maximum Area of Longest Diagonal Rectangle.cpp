// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/description/?envType=daily-question&envId=2025-08-26

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        int maxDiaLen = -1;

        for(auto &rec: dimensions){
            int diaLen = rec[0]*rec[0] + rec[1]*rec[1];
            int area = rec[0]*rec[1];

            if(diaLen > maxDiaLen || (diaLen == maxDiaLen && area > maxArea)){
                maxDiaLen = diaLen;
                maxArea = area;
            }
        }

        return maxArea;
    }
};