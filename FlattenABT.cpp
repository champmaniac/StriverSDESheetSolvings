// TC O(N) SC O(N) 
class Solution{
public:
	void flattente(TreeNode* root){
		if(root)
			revPreOrder(root);
	}
private:
	TreeNode* head = nullptr;
	void revPreOrder(TreeNode* node){
		if(node->right) revPreOrder(node->right);
		if(node->left) revPreOrder(node->left);
		node->right = head, node->left=nullptr, head =node;
	}
};
