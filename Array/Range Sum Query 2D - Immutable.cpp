// https://leetcode.com/problems/range-sum-query-2d-immutable/description/

class NumMatrix {
    private:
        vector<vector<int>> sumMat;
    public:
        NumMatrix(vector<vector<int>>& matrix) {
            int rows=matrix.size(), cols=matrix[0].size();
            sumMat = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));
    
            for(int i=0; i<rows; i++){
                int prefixSum = 0;
    
                for(int j=0; j<cols; j++){
                    prefixSum += matrix[i][j];
                    int above = sumMat[i][j+1];
                    sumMat[i+1][j+1] = prefixSum + above;
                }
            }
        }
        
        int sumRegion(int row1, int col1, int row2, int col2) {
            row1++; col1++; row2++; col2++;
            int total = sumMat[row2][col2];
            int rowSum = sumMat[row1-1][col2];
            int colSum = sumMat[row2][col1-1];
            int extra = sumMat[row1-1][col1-1];
    
            return (total - rowSum - colSum + extra);
        }
    };
    
    /**
     * Your NumMatrix object will be instantiated and called as such:
     * NumMatrix* obj = new NumMatrix(matrix);
     * int param_1 = obj->sumRegion(row1,col1,row2,col2);
     */