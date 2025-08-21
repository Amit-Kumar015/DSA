// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:
    bool checkPali(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;

            l++;
            r--;
        }

        return true;
    }

    void partition(string &s, vector<string> &tmp, vector<vector<string>> &res, int i){
        if(i >= s.length()){
            res.push_back(tmp);
            return;
        } 

        for(int j=i; j<s.length(); j++){
            if(checkPali(s, i, j)){
                tmp.push_back(s.substr(i, j-i+1));
                partition(s, tmp, res, j+1);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;

        partition(s, tmp, res, 0);
        return res;
    }
};