// https://leetcode.com/problems/task-scheduler/description/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(char task: tasks){
            count[task - 'A']++;
        }

        priority_queue<int> maxH;
        for(int i: count){
            if(i>0) maxH.push(i);
        }

        int time=0;
        queue<pair<int, int>> q;
        while(!maxH.empty() || !q.empty()){
            time++;

            if(maxH.empty()){
                time = q.front().second;
            }
            else{
                int cnt = maxH.top() - 1;
                maxH.pop();
                if(cnt > 0) q.push({cnt, time+n});
            }

            if(!q.empty() && q.front().second == time){
                maxH.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};