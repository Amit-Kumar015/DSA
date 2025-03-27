// https://leetcode.com/problems/merge-strings-alternately/description/

class Solution {
    public:
        string mergeAlternately(string word1, string word2) {
            int len1 = word1.length();
            int len2 = word2.length();
    
            string ans;
            int i=0;
            int j=0;
    
            while(i < len1 && j <len2){
                ans.push_back(word1[i]);
                ans.push_back(word2[j]);
                i++;
                j++;
            }
    
            while(i < len1){
                ans.push_back(word1[i]);
                i++;
            }
    
            while(j < len2){
                ans.push_back(word2[j]);
                j++;
            }
    
            return ans;
        }
    };