// https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1

pair<int, int> solve(Node* root){
    if(root == NULL){
        pair<int, int> p = {0,0};
        return p;
    }
    
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);
    
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    
    return ans;
}

class Solution {
  public:
    int diameter(Node* root) {
        // Your code here
        return solve(root).first;
    }
};