// TC  O(H) SC O(1) H --> height of the tree

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    if(root==NULL) return NULL;
    int cur = root->data;
    if(cur>P->data && cur>Q->data){
        return LCAinaBST(root->left,P,Q);
    }
    if(cur<P->data && cur<Q->data){
        return LCAinaBST(root->right,P,Q);
    }
    return root;
}
