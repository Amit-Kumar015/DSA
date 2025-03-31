// https://leetcode.com/problems/validate-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        bool validate(TreeNode* &root, long min, long max){
            if(!root) return true;
    
            bool left = validate(root->left, min, root->val);
            bool right = validate(root->right, root->val, max);
            bool BST = root->val > min && root->val < max ? true : false;
            
            return left && right && BST;
        }
    
        bool isValidBST(TreeNode* root) {
            if(!root->left && !root->right)
                return true;
    
            return validate(root, LONG_MIN, LONG_MAX);
        }
    };