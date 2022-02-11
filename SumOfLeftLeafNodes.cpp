int sum=0;
void helper(Node* root){
    if(!root) return;
    helper(root->left);
    helper(root->right);
    if(root->left!=NULL){
        if(root->left->left==NULL && root->left->right==NULL)
            sum+=root->left->data;
    }
}
int leftLeavesSum(Node *root)
{
    // Code here
    sum=0;
    helper(root);
    return sum;
}