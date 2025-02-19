// https://www.geeksforgeeks.org/problems/sum-tree/1

class Solution {
    pair<bool, int> solve(Node* root){
        
        if(root == NULL){
            pair<bool, int> p = {true, 0};
            return p;
        }
        
        if(root->left == NULL && root->right == NULL){
            pair<bool, int> p = {true, root->data};
            return p;
        }
        
        pair<bool, int> left = solve(root->left);
        pair<bool, int> right = solve(root->right);
        
        bool sum = root->data == left.second + right.second;
        
        return {left.first && right.first && sum, root->data + left.second + right.second};
    }
    
  public:
    bool isSumTree(Node* root) {
        // Your code here
        return solve(root).first;
    }
};