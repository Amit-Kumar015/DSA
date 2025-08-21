// https://leetcode.com/problems/jump-game-iii/description/

class Solution {
    unordered_map<int, bool> visited;
    int n;
public:
    bool dfs(vector<int>& arr, int start){
        if(arr[start] == 0) return true;
        if(visited[start] == true) return false;
        visited[start] = true;

        if(start + arr[start] < n && dfs(arr, start + arr[start])) return true;
        if(start - arr[start] >= 0 && dfs(arr, start - arr[start])) return true;

        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        return dfs(arr, start);
    }
};