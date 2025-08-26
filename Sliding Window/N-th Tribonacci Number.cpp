// https://leetcode.com/problems/n-th-tribonacci-number/description/

class Solution {
public:
    int tribonacci(int n) {
        int t0 = 0, t1 = 1, t2 = 1;
        int t3 = 0;

        if(n == 1 || n == 2) return 1;

        for(int i = 0; i<n-3+1; i++){
            t3 = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = t3;
        }

        return t3;
    }
};