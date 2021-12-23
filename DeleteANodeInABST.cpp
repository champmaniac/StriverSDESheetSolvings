TreeNode * deleteNode(TreeNode* root, int key){
	if(root==NULL) return NULL;
	if(root->val==key){
		return helper(root);
	}

	TreeNode* dummy = root;
	while(root!=NULL){
		if(root->val>key){
			if(root->left!=NULL && root->left->val==key){
				root->left=helper(root->left);
				break;
			}
			else{
				root=root->left;
			}
		}
		else
		{
			if(root->right!=NULL && root->right->val==key){
				root->right=helper(root->right);
				break;
			}
			else
			{
				root = root->right;
			}
		}
	}
	return dummy;
}

TreeNode * helper(TreeNode* root){
	if(root->left==NULL)
		return root->right;
	if(root->right==NULL)
		return root->left;

	TreeNode* rightchild = root->right;
	TreeNode* lastRight = findlastRight(root->left);
	lastRight->right = rightchild;
	return  root->left; 
}

TreeNode* findlastRight(TreeNode* root){
	if(root->right==NULL) return root;
	return findlastRight(root->right);
}