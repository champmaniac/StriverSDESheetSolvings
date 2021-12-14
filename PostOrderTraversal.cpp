void dfs(TreeNode* root, vector<int> &postOrder){
    if(root==NULL)
        return;
    dfs(root->left,postOrder);
    dfs(root->right,postOrder);
    postOrder.push_back(root->val);

}
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> postOrder;
    dfs(root,postOrder);
    return postOrder;
}
