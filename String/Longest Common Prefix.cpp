// https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            for(int i=0; i<strs[0].length(); i++){
                for(const string& s: strs){
                    if(i == s.length() || s[i] != strs[0][i]){
                        return s.substr(0, i);
                    }
                }
            }
    
            return strs[0];
        }
    };

// sorting
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(strs.size() == 1){
                return strs[0];
            }
    
            sort(strs.begin(), strs.end());
    
            for(int i=0; i<min(strs[0].length(), strs.back().length()); i++){
                if(strs[0][i] != strs.back()[i]){
                    return strs[0].substr(0, i);
                }
            }
    
            return strs[0];
        }
    };