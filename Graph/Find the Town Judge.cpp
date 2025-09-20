// https://leetcode.com/problems/find-the-town-judge/description/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1) return 1;

        vector<int> inGoing(n+1, 0);
        vector<int> outGoing(n+1, 0);

        for(auto& entry: trust){
            outGoing[entry[0]]++;
            inGoing[entry[1]]++;
        }

        for(int i=0; i<=n; i++){
            if(inGoing[i] == n-1 && outGoing[i] == 0) return i;
        }
        return -1;
    }
};