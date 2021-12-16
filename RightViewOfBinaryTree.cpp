void dfs(TreeNode<int> *root, int level, vector<int> &res){
    if(root==NULL) return;
    if(res.size()==level) res.push_back(root->data);
    dfs(root->right,level+1,res);
    dfs(root->left,level+1,res);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> res;
    dfs(root,0,res);
    return res;
}