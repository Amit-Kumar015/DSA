// https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

class Solution {
    pair<bool, int> solve(Node* root){
        if(root == NULL){
            pair<bool, int> p = {true, 0};
            return p;
        }
        
        pair<bool, int> left = solve(root->left);
        pair<bool, int> right = solve(root->right);
        
        int leftHeight = left.second;
        int rightHeight = right.second;
        
        pair<bool, int> ans;
        
        bool isLeftBalanced = left.first;
        bool isRightBalanced = right.first;
        bool heightDiff = abs(leftHeight - rightHeight) <= 1;
        
        bool isBalanced = isLeftBalanced && isRightBalanced && heightDiff;
        
        return {isBalanced, max(leftHeight, rightHeight) + 1}
    }
    
  public:
    bool isBalanced(Node* root) {
        // Code here
        return solve(root).first;
    }
};