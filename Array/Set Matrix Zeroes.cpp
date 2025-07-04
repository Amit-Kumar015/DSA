// https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<bool>  rowZero(row, 0);
        vector<bool>  colZero(col, 0);

        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(matrix[r][c] == 0){
                    rowZero[r] = 1;
                    colZero[c] = 1;
                }
            }
        }

        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(rowZero[r] || colZero[c]){
                    matrix[r][c] = 0;
                }
            }
        }
    }
};

// optimised
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool rowZero = false;

        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(matrix[r][c] == 0){
                    matrix[0][c] = 0;
                    if(r > 0){
                        matrix[r][0] = 0;
                    }
                    else{
                        rowZero = true;
                    }
                }
            }
        }

        for(int r=1; r<row; r++){
            for(int c=1; c<col; c++){
                if(matrix[r][0] == 0 || matrix[0][c] == 0) matrix[r][c] = 0;
            }
        }
        if (matrix[0][0] == 0) {
            for (int r = 0; r < row; r++) {
                matrix[r][0] = 0;
            }
        }

        if (rowZero) {
            for (int c = 0; c < col; c++) {
                matrix[0][c] = 0;
            }
        }
    }
};