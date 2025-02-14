// https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

int height(Node* node) {
    if(node ==  NULL){
        return 0;
    }
    
    int leftCount = height(node->left);
    int rightCount = height(node->right);
    
    int ans = max(leftCount, rightCount) + 1;
    
    return ans;
}