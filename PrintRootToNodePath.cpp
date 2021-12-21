// TC O(N) SC O(N)

bool getPath(Node* root,vector<int> &arr, int x){
	if(!root) return false;
	arr.push_back(root->data);
	if(root->data==x)
		return true;
	if(getPath(root->left,arr,x)|| getPath(root->right,arr,x))
		return true;
	arr.pop_back();
	return false;
}

vector<int> rootToNodePath(Node* root, int x){
	vector<int> arr;
	getPath(root,arr,x);
	return arr;
}