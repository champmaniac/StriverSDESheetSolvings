// TC O(N) SC O(N)


void dfs(TreeNode* root,vector<int> &inOrder){
    if(root==NULL)
        return;
    dfs(root->left,inOrder);
    inOrder.push_back(root->val);
    dfs(root->right,inOrder);

    
}
vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> inOrder;
    dfs(root,inOrder);
    return inOrder;
}