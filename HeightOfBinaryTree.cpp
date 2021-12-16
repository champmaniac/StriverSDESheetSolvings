// TC O(N) SC O(height)
vector<int> maxDepth(TreeNode* root){
	if(root==NULL){
		return;
	}

	int lh = maxDepth(root->left);
	int rh = maxDepth(root->right);

	return 1+max(lh,rh);
}