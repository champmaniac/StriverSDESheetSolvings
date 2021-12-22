void reorder(BinaryTreeNode<int>*root){
	if(root==NULL) return root;
	int child=0;
	if(root->left){
		child+=root->left->data;
	}
	if(root->right)
	{
		child+=root->right->data;
	}

	if(child>=root->data)
		root->data =child;
	else
	{
		if(root->left)
			root->left->data=root->data;
		else
			root->right->data=root->data;

	}

	reorder(root->left);
	reorder(root->right);

	int total =0;
	if(root->left) total+=root->left->data;
	if(root->right) total+=root->right->data;	

	if(root->left || root->right) root->data = total;
}

void changeTree(BinaryTreeNode<int>* root){
	reorder(root);
}