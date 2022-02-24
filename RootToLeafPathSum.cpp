void pre(Node* root,long long &ans, long long temp)
{
    if(!root) return;
    temp =temp*10+root->data;
    if(!root->left && !root->right) ans+=temp;
    pre(root->left,ans,temp);
    pre(root->right,ans,temp);
}

long long treePathsSum(Node *root)
{
    //Your code here
    long long ans=0ll;
    pre(root,ans,0ll);
    return ans;
}