// TC O(H) SC O(1)
TreeNode* inoderSuccessor(TreeNode* root,TreeNode* p){
	TreeNode* successor = NULL;
	while(root!=NULL){
		if(p->val>=root->val)
			root = root->right;
		else{
			successor=root->val;
			root=root->left;
		}
	}
	return successor;
}