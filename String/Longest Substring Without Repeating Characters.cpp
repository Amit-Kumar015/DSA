// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            map<char, bool> m;
            int l=0;
            int r=0;
            int maxi=0;
    
            if(!s.length()){
                return 0;
            }
    
            while(r < s.length()){
                if(m[s[r]]){
                    m[s[l]] = 0;
                    l++;           
                }
                else{
                    maxi = max(maxi, r-l+1);
                    m[s[r]] = 1;
                    r++;
                }
            }
    
            return maxi;
        }
    };