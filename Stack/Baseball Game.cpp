// https://leetcode.com/problems/baseball-game/description/

#include<stack>

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;

        for(auto i: operations){
            if(i == "+"){
                int top1 = s.top();
                s.pop();
                int top2 = s.top();
                int total = top1 + top2;

                s.push(top1);
                s.push(total);
            }
            else if(i == "D"){
                int top = s.top();
                s.push(2*top);
            }
            else if(i == "C"){
                s.pop();
            }
            else{
                s.push(stoi(i));
            }
        }

        int total=0;
        while(!s.empty()){
            int pop = s.top();
            s.pop(); 
            total += pop;
        }

        return total;
    }
};