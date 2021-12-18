TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
	if(root==NULL || root==p || root==q){
		return root;
	}

	TreeNode* left = lowestCommonAncestor(root->left,p,q);
	TreeNode* right= lowestCommonAncestor(root->right,p,q);

	if(left==NULL) // only left null? then right
		return right;
	else if(right ==NULL) // only right null? then left
		return left;
	else // both not null? then root
		return root;
}