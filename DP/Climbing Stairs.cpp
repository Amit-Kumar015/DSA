// https://leetcode.com/problems/climbing-stairs/description/

// top-down
class Solution {
    unordered_map<int, int> m;
public:
    int climbStairs(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(m[n]) return m[n];

        int cnt = climbStairs(n-1) + climbStairs(n-2);
        m[n] = cnt;
        return cnt;
    }
};

// bottom-up
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> dp(n+1);

        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// space optimized
class Solution {
public:
    int climbStairs(int n) {
        int one = 1;
        int two = 1;

        int i=0;
        while(i < n-1){
            int temp = one;
            one = one + two;
            two = temp;
            i++;
        }
        return one;
    }
};