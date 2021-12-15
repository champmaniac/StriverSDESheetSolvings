// Using two Stacks
vector<int> postorderTraversal(TreeNode *root){
	vector<int> postOrder;
	if(root==NULL) return postOrder;
	stack<TreeNode*> st1, st2;
	st1.push(root);
	while(!st1.empty()){
		root = st1.top();
		st1.pop();
		st2.push(root);
		if(root->left!=NULL)
		{
			st1.push(root->left);
		}
		if(root->right!=NULL)
			st1.push(root->right);
	}

	while(!st2.empty()){
		postOrder.push_back(st2.top()->val);
		st2.pop();
	}
	return postOrder;
}
// using one stack

vector<int> postorderTraversal(TreeNode *root){
	vector<int> postOrder;
	if(root==NULL) return postOrder;
	stack<TreeNode*> st;
	TreeNode* curr = root;
	while(curr!=NULL || !st.empty()){
		if(curr!=NULL){
			st.push(curr);
			curr = curr->left;
		}
		else
		{
			temp = st.top()->right;
			if(temp==NULL){
				temp=st.top();
				st.pop();
				postOrder.push_back(temp);
				while(!st.empty() && temp==st.top()->right){
					temp = st.top(), st.pop();
					postOrder.push_back(temp->val);
				}
			}
			else
				curr =temp;
	}
	return postOrder;

}