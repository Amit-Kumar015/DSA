// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
private:
    void solve(int x, int y, vector<string>& ans, vector<vector<int>>& mat, vector<vector<int>>& visited, string path, int n) {
        // Base case: if the destination is reached
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        // Mark the current cell as visited
        visited[x][y] = 1;

        // Move Down
        if (x + 1 < n && !visited[x + 1][y] && mat[x + 1][y] != 0) {
            path.push_back('D');
            solve(x + 1, y, ans, mat, visited, path, n);
            path.pop_back();
        }

        // Move Left
        if (y - 1 >= 0 && !visited[x][y - 1] && mat[x][y - 1] != 0) {
            path.push_back('L');
            solve(x, y - 1, ans, mat, visited, path, n);
            path.pop_back();
        }

        // Move Right
        if (y + 1 < n && !visited[x][y + 1] && mat[x][y + 1] != 0) {
            path.push_back('R');
            solve(x, y + 1, ans, mat, visited, path, n);
            path.pop_back();
        }

        // Move Up
        if (x - 1 >= 0 && !visited[x - 1][y] && mat[x - 1][y] != 0) {
            path.push_back('U');
            solve(x - 1, y, ans, mat, visited, path, n);
            path.pop_back();
        }

        // Backtrack: Unmark the current cell
        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<string> ans;

        // If the starting or ending cell is blocked
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
            return ans;
        }

        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";
        solve(0, 0, ans, mat, visited, path, n);
        return ans;
    }
};