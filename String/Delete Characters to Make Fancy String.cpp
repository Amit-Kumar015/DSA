// https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2025-07-21

class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int l=0, r=0;

        while(r < s.length()){
            if(s[l] == s[r] && r-l >= 2){
                r++;
                continue;
            }

            if(s[l] != s[r]) l = r;

            ans += s[r];
            r++;
        }
        return ans;
    }
};