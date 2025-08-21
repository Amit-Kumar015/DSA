// https://leetcode.com/problems/jump-game-vii/description/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int size = s.length();
        queue<int> q;
        q.push(0);
        int farthest = 0;

        while(!q.empty()){
            int i = q.front();
            q.pop();

            int start = max(i + minJump, farthest + 1);

            for(int j=start; j<min(i + maxJump + 1, size); j++){
                if(s[j] == '0'){
                    q.push(j);
                    if(j == size-1) return true;
                }
            }
            farthest = i + maxJump;
        }

        return false;
    }
};