int height(BinaryTreeNode<int>* root){
    if(!root) return 0;
    return max(height(root->left),height(root->right))+1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(!root) return true;
    return abs(height(root->left)-height(root->right))<=1 && isBalancedBT(root->left) && isBalancedBT(root->right);
}