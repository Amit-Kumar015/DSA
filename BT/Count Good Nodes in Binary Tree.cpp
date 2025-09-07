// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

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
    int res = 0;
public:
    void dfs(TreeNode* root, int maxVal){
        if(!root) return;

        dfs(root->left, max(maxVal, root->val));
        dfs(root->right, max(maxVal, root->val));

        if(root->val >= maxVal){
            cout<<root->val;
            res++;
        }
    }

    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return res;
    }
};