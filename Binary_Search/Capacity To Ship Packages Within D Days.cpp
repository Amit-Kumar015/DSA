// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
    private:
        bool isPossible(vector<int>& weights, int days, int mid){
            int ships=1, cap=mid;
    
            for(int w :weights){
                if(cap - w < 0){
                    ships++;
    
                    if(ships > days){
                        return false;
                    }
                    cap = mid;
                }
    
                cap -= w;
            }
    
            return true;
        }
    
    public:
        int shipWithinDays(vector<int>& weights, int days) {
            int n=weights.size();
            int ans=0;
    
            int s= *max_element(weights.begin(), weights.end());
            long long e= accumulate(weights.begin(), weights.end(), 0);
    
            while(s<=e){
                long long mid = s+(e-s)/2;
    
                if(isPossible(weights, days, mid)){
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