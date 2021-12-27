// Preorder Traversal
// TC O(N) SC O(N)

BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int p, int q, int r) {
    // Write your code here.
    if(root==NULL || root->data==p || root->data==q || root->data==r){
        return root;
    }
    BinaryTreeNode<int>* left = lcaOfThreeNodes(root->left,p,q,r);
    BinaryTreeNode<int>* right =lcaOfThreeNodes(root->right,p,q,r);
    
    if(left!=NULL && right!=NULL) // both not null, then root
        return root;
    if(left!=NULL) // only left, then return left
        return left;
    else // only right, then return right
        return right;
}
