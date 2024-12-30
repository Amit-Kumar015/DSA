// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        for (char& c : s) {
            c = tolower(c); 
        }

        int i=0;
        int j=s.size()-1;

        while(i < j){
            if((s[i] < 'a' || s[i] > 'z') &&
            (s[i] < '0' || s[i] > '9')){
                i++;
            }
            else if((s[j] < 'a' || s[j] > 'z') && 
            (s[j] < '0' || s[j] > '9')){
                j--;
            }
            else if(s[i] != s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }

        }
        return true;
    }
};