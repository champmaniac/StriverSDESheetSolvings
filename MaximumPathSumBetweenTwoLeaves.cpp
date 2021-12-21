#include<bits/stdc++.h>
long long int maxSum(TreeNode<int>* root,long long int &maxi){
    if (root == NULL)
    {
        return -1;
    }
    if(root->left == NULL && root->right==NULL)
        return root->val;
    
    long long int leftSum =maxSum(root->left,maxi);
    long long int rightSum = maxSum(root->right,maxi);
    if(root->left!=NULL && root->right!=NULL)
    {
        maxi = max(maxi, leftSum+rightSum+root->val);
        return max(leftSum,rightSum)+root->val;
    }
    else if(root->left==NULL)
        return rightSum+root->val;
    else
        return leftSum+root->val;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    long long int maxi = -1;
    maxSum(root,maxi);
    return maxi;
}