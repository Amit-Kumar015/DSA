// https://www.geeksforgeeks.org/problems/queue-reversal/1

// recursion
class Solution {
    void solve(queue<int> &q){
        if(q.empty()){
            return;
        }
        
        int front = q.front();
        q.pop();
        
        solve(q);
        q.push(front);
    }
  public:
    queue<int> reverseQueue(queue<int> &q) {
        // code here.
        solve(q);
        return q;
    }
};


// using stack
class Solution {
    public:
      queue<int> reverseQueue(queue<int> &q) {
          // code here.
          stack<int> s;
          
          while(!q.empty()){
              s.push(q.front());
              q.pop();
          }
          
          while(!s.empty()){
              q.push(s.top());
              s.pop();
          }
          return q;
      }
  };