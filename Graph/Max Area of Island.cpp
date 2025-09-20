// https://leetcode.com/problems/max-area-of-island/description/

class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visit){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || visit[i][j]){
            return 0;
        }

        visit[i][j] = true;
        int area = dfs(i, j+1, grid, visit);
        area += dfs(i+1, j, grid, visit);
        area += dfs(i, j-1, grid, visit);
        area += dfs(i-1, j, grid, visit);

        area += 1;
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        int maxArea = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1 && !visit[i][j]){
                    int area = dfs(i, j, grid, visit);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};