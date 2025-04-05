// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int rows = matrix.size();
            int col = matrix[0].size();
    
            int top = 0, bott = rows - 1;
            while (top <= bott) {
                int row = top + (bott - top) / 2;
    
                if (target > matrix[row][col - 1]) {
                    top = row + 1;
                } else if (target < matrix[row][0]) {
                    bott = row - 1;
                } else {
                    break; 
                }
            }
    
            if (!(top <= bott)) return false;
    
            int row = top + (bott - top) / 2;
            int l = 0, r = col - 1;
    
            while (l <= r) {
                int m = l + (r - l) / 2;
    
                if (target < matrix[row][m]) {
                    r = m - 1;
                } else if (target > matrix[row][m]) {
                    l = m + 1;
                } else {
                    return true;
                }
            }
    
            return false;
        }
    };
    