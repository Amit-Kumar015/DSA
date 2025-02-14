// https://www.naukri.com/code360/problems/count-leaf-nodes_893055?source=youtube&campaign=LoveBabbar_Codestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudio&leftPanelTabValue=PROBLEM

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
void solve(BinaryTreeNode<int> *root, int &cnt){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        cnt++;
        return;
    }

    solve(root->left, cnt);
    solve(root->right, cnt);
}


int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt=0;
    solve(root, cnt);

    return cnt;
}