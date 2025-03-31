// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
        vector<int> rightSideView(TreeNode* root) {
            vector<int> ans;
            queue<TreeNode*> q;
    
            if(!root) return ans;
    
            q.push(root);
            q.push(NULL);
    
            while(!q.empty()){
                TreeNode* temp = q.front();
                q.pop();
    
                if(!q.front()) ans.push_back(temp->val);
    
                if(!temp){
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }
                else{
                    if(temp->left) q.push(temp->left);
    
                    if(temp->right) q.push(temp->right);
                }
            }
    
            return ans;
        }
    };