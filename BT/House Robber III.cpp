// https://leetcode.com/problems/house-robber-iii/description/

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
    pair<int, int> dfs(TreeNode* root){
        if(!root) return {0,0};
        if(!root->left && !root->right) return {root->val, 0};

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        int with = root->val + left.second + right.second;
        int without = max(left.first, left.second) + max(right.first, right.second);

        return {with, without};
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> ans = dfs(root);
        return max(ans.first, ans.second);
    }
};