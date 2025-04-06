// https://leetcode.com/problems/majority-element/description/

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int res=0, count=0;
            for(int num: nums){
                if(count == 0){
                    res = num;
                }
                
                count += (res == num) ? 1 : -1;
            }
    
            return res;
        }
    };


class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            map<int, int> m;
    
            for(int i=0; i<nums.size(); i++){
                m[nums[i]]++;
            }
    
            int maxVal = INT_MIN;
            int ans=-1;
    
            for(auto& val: m){
                if(val.second > maxVal){
                    maxVal = val.second;
                    ans = val.first;
                }
            }
    
            return ans;
        }
    };