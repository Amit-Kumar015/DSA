// https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char i: s){
            freq[i]++;
        }

        vector<pair<char, int>> arr(freq.begin(), freq.end());
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        string ans = "";
        for(auto &pair: arr){
            ans.append(pair.second, pair.first);
        }
        return ans;
    }
};