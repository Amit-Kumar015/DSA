class Solution {
public:
    vector<int> distinctNumbers(vector<int> &nums, int k) {
        vector<int> res;
        unordered_map<int, int> freq;

        for(int i=0; i<k; i++){
            freq[nums[i]]++;
        }
        res.push_back(freq.size());
        int l=0, r=k;

        while(r < nums.size()){
            freq[nums[r]]++;
            r++;

            freq[nums[l]]--;
            if(freq[nums[l]] == 0){
                freq.erase(nums[l]);
            }
            l++;
            res.push_back(freq.size());
        }

        return res;
    }