// https://leetcode.com/problems/gas-station/description/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;

        int total = 0;
        int start = 0;
        int n = gas.size();
        for(int i=0; i<n; i++){
            total += gas[i] - cost[i];

            if(total < 0){
                total = 0;
                start = i+1;
            } 
        }

        return start;
    }
};