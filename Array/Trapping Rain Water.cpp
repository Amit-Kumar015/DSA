// https://leetcode.com/problems/trapping-rain-water/description/

// easy to understand
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        int lmax=0;
        for(int l=0; l<n; l++){
            leftMax[l] = lmax;
            lmax = max(lmax, height[l]);
        }

        int rmax=0;
        for(int r=n-1; r>=0; r--){
            rightMax[r] = rmax;
            rmax = max(rmax, height[r]);
        }

        int total=0;
        for(int i=0; i<n; i++){
            int water = min(leftMax[i], rightMax[i]) - height[i];
            if(water > 0){
                total += water;
            }
        }
        return total;
    }
};

// with 2 pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1;
        int lmax=0, rmax=0;
        int total = 0;

        while(l <= r){
            if(lmax <= rmax){
                int water = lmax - height[l];
                if(water > 0) total += water;
                lmax = max(lmax, height[l]);
                l++;
            }
            else{
                int water = rmax - height[r];
                if(water > 0) total += water;
                rmax = max(rmax, height[r]);
                r--;
            }
        }
        return total;
    }
};