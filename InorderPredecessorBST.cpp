// TC O(H) SC O(1)
TreeNode* inorderPredecessor(TreeNode* root,TreeNode* p){
	TreeNode* predecessor = NULL;
	while(root!=NULL){
		if(p->val>=root->val)
			predecessor=root->val;
			root = root->right;
		else{
			root=root->left;
		}
	}
	return predecessor;
}