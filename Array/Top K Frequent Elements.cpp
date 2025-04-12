// https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> count;
            vector<vector<int>> freq(nums.size() + 1);
            vector<int> ans;
    
            for(int num: nums){
                count[num] += 1;
            }
    
            for(auto entry: count){
                freq[entry.second].push_back(entry.first);
            }
    
            for(int i=freq.size()-1; i>0; i--){
                for(int n: freq[i]){
                    ans.push_back(n);
                    if(ans.size() == k){
                        return ans;
                    }
                }
            }
    
            return ans;
        }
    };