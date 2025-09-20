// https://leetcode.com/problems/island-perimeter/description/

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &visited, int &perimeter){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            perimeter++;
            return;
        }
        if(visited[i][j]) return;

        visited[i][j] = true;
        // left
        dfs(i-1, j, grid, visited, perimeter);
        // down
        dfs(i, j+1, grid, visited, perimeter);
        //right
        dfs(i+1, j, grid, visited, perimeter);
        //top
        dfs(i, j-1, grid, visited, perimeter);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int perimeter = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){
                   dfs(i, j, grid, visited, perimeter);
                } 
            }
        }

        return perimeter;
    }
};