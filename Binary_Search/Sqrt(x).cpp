// https://leetcode.com/problems/sqrtx/description/

class Solution {
    public:
        int mySqrt(int x) {
            if(x == 0 || x == 1){
                return x;
            }
    
            int s=1;
            int e=x;
            long long int mid = s+(e-s)/2;
            int ans=-1;
    
            while(s <= e){
                if(mid * mid == x){
                    ans = mid;
                    return ans;
                }
                else if(mid * mid < x){
                    ans = mid;
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
    
                mid = s+(e-s)/2;
            }
    
            return ans;
        }
    };