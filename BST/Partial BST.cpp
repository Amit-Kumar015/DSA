// https://www.naukri.com/code360/problems/validate-bst_799483?leftPanelTab=0&leftPanelTabValue=PROBLEM

bool isBST(BinaryTreeNode<int> *root, int min, int max){
    if(root == NULL){
        return true;
    }

    if(root->data >= min && root->data <= max){
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else{
        return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root, INT_MIN, INT_MAX);
}

// less optimised
void inOrder(BinaryTreeNode<int> *root, vector<int>& ans){
    if(root == NULL){
        return;
    }

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

bool validateBST(BinaryTreeNode<int> *root) {
    vector<int> ans;
    inOrder(root, ans);

    for(int i=1; i<ans.size(); i++){
        if(ans[i] < ans[i-1]){
            return false;
        }
    }
    return true;
}