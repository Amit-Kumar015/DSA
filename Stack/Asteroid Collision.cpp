// https://leetcode.com/problems/asteroid-collision/description/

class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            vector<int> st;
    
            for(int a: asteroids){
                while(!st.empty() && a < 0 && st.back() > 0){
                    int diff = a + st.back();
    
                    if(diff == 0){
                        st.pop_back();
                        a=0;
                    }
                    else if(diff < 0){
                        st.pop_back();
                    }
                    else{
                        a=0;
                    }
                }
    
                if(a != 0){
                    st.push_back(a);
                }
            }
    
            return st;
        }
    };