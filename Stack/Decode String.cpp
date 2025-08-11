// https://leetcode.com/problems/decode-string/description/

// using stack
class Solution {
public:
    string decodeString(string s) {
        vector<string> stack;

        for(char& c: s){
            if(c != ']'){
                stack.push_back(string(1, c));
            }
            else{
                string substr = "";
                while(stack.back() != "["){
                    substr = stack.back() + substr;
                    stack.pop_back();
                }
                stack.pop_back();

                string k = "";
                while(!stack.empty() && isdigit(stack.back()[0])){
                    k = stack.back() + k;
                    stack.pop_back();
                }
                
                int repeatCount = stoi(k);
                string repeated = "";
                while(repeatCount){
                    repeated += substr;
                    repeatCount--;
                }
                stack.push_back(repeated);
            }
        }

        string ans = "";
        for(string& part: stack){
            ans += part;
        }
        return ans;
    }
};

// using recursion
class Solution {
public:
    string helper(int &i, string &s){
        int k = 0;
        string res = "";

        while(i < s.size()){
            char c = s[i];

            if(isdigit(c)){
                k = k*10 + (c - '0');
            }
            else if(c == '['){
                i++;
                string substr = helper(i, s);
                while(k){
                    res += substr;
                    k--;
                }
            }
            else if(c == ']'){
                return res;
            }
            else{
                res += c;
            }
            i++;
        }

        return res;
    }

    string decodeString(string s) {
        int i=0;
        string ans = helper(i, s);
        return ans;
    }
};