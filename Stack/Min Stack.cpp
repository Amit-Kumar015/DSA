// https://leetcode.com/problems/min-stack/description/

// optimised
class MinStack {
    stack<int> s;
    stack<int> mins;
public:
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(mins.empty()){
            mins.push(val);
        }
        else{
            if(val <= mins.top()){
                mins.push(val);
            }
            else{
                mins.push(mins.top());
            }
        }
    }
    
    void pop() {
        s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
*/

class MinStack {
    stack<int> s;
public:
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        int min = INT_MAX;
        stack<int> temp;

        while(!s.empty()){
            if(min >= s.top()){
                min = s.top();
            }

            temp.push(s.top());
            s.pop();
        }

        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }

        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */