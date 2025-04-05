// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int row=matrix.size(), col=matrix[0].size();
            int r=0, c=matrix[0].size()-1;
    
            while(r<row && c>=0){
                if(matrix[r][c] == target){
                    return true;
                }
                else if(matrix[r][c] > target){
                    c--;
                }
                else{
                    r++;
                }
            }
    
            return false;
        }
    };