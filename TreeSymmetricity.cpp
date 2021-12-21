bool f(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    if(!root1) return !root2;
    if(!root2) return !root1;
    return (root1->data == root2->data) && f(root1->left,root2->right) && f(root1->right,root2->left);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.
    if(!root) return true;
    return f(root->left,root->right);
}