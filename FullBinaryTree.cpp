bool isFullTree (struct Node* root)
{
//add code here.
if(root==NULL)
    return true;
else if(root->left==NULL && root->right==NULL) return true;
else if(root->left!=NULL && root->right!=NULL) return isFullTree(root->left)&& isFullTree(root->right);
else if(root->left || root->right) return false;
}