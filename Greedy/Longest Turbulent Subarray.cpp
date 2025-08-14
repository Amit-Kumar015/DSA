// https://leetcode.com/problems/longest-turbulent-subarray/description/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int sign = -1;
        int cnt = 0, res = 0;

        for(int i=0; i<n-1; i++){
            if(arr[i] < arr[i+1]){
                cnt = (sign == 0) ? cnt+1 : 1;
                sign = 1;
            }
            else if(arr[i] > arr[i+1]){
                cnt = (sign == 1) ? cnt+1 : 1;
                sign = 0;
            }
            else{
                sign = -1;
                cnt = 0;
            }

            res = max(res, cnt);
        }

        return res+1;
    }
};