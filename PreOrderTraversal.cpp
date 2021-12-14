// TC O(N) SC O(N)


void dfs(TreeNode* root,vector<int> &predOrder){
    if(root==NULL)
        return;
    predOrder.push_back(root->val);
    dfs(root->left,predOrder);
    dfs(root->right,predOrder);

    
}
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> predOrder;
    dfs(root,predOrder);
    return predOrder;
}