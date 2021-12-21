class Solution{
	bool isleaf(Node* root){
		return !root->left && !root->right;
	}

	void addLeftBoundary(Node* root, vector<int> &res){
		Node* curr = root->left;
		if(!isleaf(curr)) res.push_back(curr->data);
		if(curr->left) curr = curr->left;
		else curr=curr->right;
	}
	// reverse right boundary
	void addRightBoundary(Node* root, vector<int> &res){
		Node* curr = root->right;
		vector<int> st;
		while(cur){
			if(!isleaf(curr)) st.push_back(curr->data);
			if(curr->right) curr=curr->right;
			else curr = curr->right;
		}

		for(int i=st.size()-1;i>=0;--i){
			res.push_back(st[i]);
		}
	}

	void addLeaves(Node* root,vector<int> &res){
		if(isleaf(root)){
			res.push_back(root->data);
			return;
		}
		if(root->left) addLeaves(root->left,res);
		if(root->right) addLeaves(root->right,res);
	}


public:
	vector<int> printBoundary(Node* root){
		vector<int> res;
		if(!root) return res;

		if(!isleaf(root)) res.push_back(root->data);
		// adding left boundary
		addLeftBoundary(root,res);
		// add leaves
		addLeaves(root,res);
		// adding reversed right boundary
		addRightBoundary(root,res);
		return res;
	}
}