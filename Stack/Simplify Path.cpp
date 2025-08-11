// https://leetcode.com/problems/simplify-path/description/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st; 
        string curr = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (curr == "" || curr == ".") {
                    // ignore empty or "."
                } 
                else if (curr == "..") {
                    if (!st.empty()) st.pop_back(); // go back
                } 
                else {
                    st.push_back(curr); // valid folder name
                }
                curr.clear();
            } 
            else {
                curr.push_back(path[i]);
            }
        }

        string ans = "/";
        for (int i = 0; i < st.size(); i++) {
            ans += st[i];
            if (i != st.size() - 1) ans += "/";
        }
        return ans;
    }
};
