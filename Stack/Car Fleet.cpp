// https://leetcode.com/problems/car-fleet/description/

//easy to understand
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int, int>> vec;

        for(int i=0; i<n; i++){
            vec.push_back({position[i], speed[i]});
        }
        sort(vec.rbegin(), vec.rend());

        int fleet=1;
        double prevTime = (double)(target - vec[0].first)/vec[0].second;
        for(int i=1; i<n; i++){
            double curTime = (double)(target - vec[i].first)/vec[i].second;
            if(curTime > prevTime){
                fleet++;
                prevTime = curTime;
            }
        }
        return fleet;
    }
};


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int, int>> vec;

        for(int i=0; i<n; i++){
            vec.push_back({position[i], speed[i]});
        }
        sort(vec.rbegin(), vec.rend());

        vector<double> stack;
        for(auto& p: vec){
            int pos = p.first;
            int sp = p.second;

            double time = (double)(target - pos)/sp;
            stack.push_back(time);
            if (stack.size() >= 2 && 
                stack.back() <= stack[stack.size() - 2]) 
            {
                stack.pop_back();
            }
        }
        
        return stack.size();
    }
};