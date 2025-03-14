// https://leetcode.com/problems/valid-anagram/description/

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length() != t.length()){
                return false;
            }
    
            vector<int> count(26, 0);
    
            for(int i=0; i<s.length(); i++){
                count[s[i] - 'a']++;
                count[t[i] - 'a']--;
            }
    
            for(int i:count){
                if(i != 0){
                    return false;
                }
            }
    
            return true;
        }
    };

// using map

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length() != t.length()){
                return false;
            }
    
            unordered_map<char, int> m;
    
            for(int i=0; i<s.length(); i++){
                m[s[i]] += 1; 
                m[t[i]] -= 1;
            }
    
            for(auto i : m){
                if(i.second != 0){
                    return false;
                }
            }
    
            return true;
        }
    };