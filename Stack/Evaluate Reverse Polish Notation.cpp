// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(auto& c: tokens){
            if(c == "+"){
                int a = s.top(); 
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b + a);
            }
            else if(c == "-"){
                int a = s.top(); 
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b - a);
            }
            else if(c == "*"){
                int a = s.top(); 
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b * a);
            }
            else if(c == "/"){
                int a = s.top(); 
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b / a);
            }
            else{
                s.push(stoi(c));
            }
        }

        return s.top();
    }
};

// recursion
class Solution {
    int dfs(vector<string>& tokens){
        string token = tokens.back();
        tokens.pop_back();

        if(token != "+" && token != "-" && token != "*" && token != "/"){
            return stoi(token);
        }

        int right = dfs(tokens);
        int left = dfs(tokens);

        if(token == "+"){
            return left + right;
        }
        else if(token == "-"){
            return left - right;
        }
        else if(token == "*"){
            return left * right;
        }
        else{
            return left / right;
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        return dfs(tokens);
    }
};