// https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution {
    public:
        int characterReplacement(string s, int k) {
            int res=0;
            unordered_set<char> charSet(s.begin(), s.end());
    
            for(char c: charSet){
                int freq=0, l=0;
                for(int r=0; r<s.length(); r++){
                    if(s[r] == c){
                        freq++;
                    }
    
                    while((r-l+1) - freq > k){
                        if(s[l] == c){
                            freq--;
                        }
                        l++;
                    }
    
                    res = max(r-l+1, res);
                }
            }
    
            return res;
        }
    };