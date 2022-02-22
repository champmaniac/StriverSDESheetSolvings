void helper(Node* node, vector<int> &ans){
    if(!node) return;
    helper(node->left,ans);
    helper(node->right,ans);
    if((node->left!=NULL && node->right==NULL) || (node->right!=NULL && node->left==NULL))
        ans.push_back(node->left?node->left->data:node->right->data);
}
vector<int> noSibling(Node* node)
{
    // code here
    vector<int> ans;
    helper(node,ans);
    sort(ans.begin(),ans.end());
    if(!ans.size()) ans.push_back(-1);
    return ans;
}