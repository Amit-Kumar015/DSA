// https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
    private:
        bool isPossible(vector<int>& piles, int h, long long mid){
            long long time=0;
            for(int i=0; i<piles.size(); i++){
                time += (piles[i] + mid-1)/mid;
            }
    
            if(time <= h){
                return true;
            }
            else{
                return false;
            }
        }
    
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int n=piles.size();
    
            int s=1;
            int e= *max_element(piles.begin(), piles.end());
            int ans=0;
    
            while(s<=e){
                long long mid = s+(e-s)/2;
    
                if(isPossible(piles, h, mid)){
                    ans=mid;
                    e=mid-1;
                }
                else{
                    s=mid+1;    
                }
            }
    
            return ans;
        }
    };