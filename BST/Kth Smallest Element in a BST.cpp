// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
        void solve(TreeNode* &root, vector<int> &temp){
            if(!root) return;
    
            solve(root->left, temp);
    
            if(temp[0] == 0){
                temp[1] = root->val;
                temp[0] = -1;
            }
            else{
                temp[0] = temp[0]-1;
            }
    
            solve(root->right, temp);
        }
        int kthSmallest(TreeNode* root, int k) {
            vector<int> temp(2);
            temp[0] = k-1;
    
            solve(root, temp);
            return temp[1];
        }
    };