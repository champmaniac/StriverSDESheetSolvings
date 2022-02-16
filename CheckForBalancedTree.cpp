class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int height(Node* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(!root) return true;
        return abs(height(root->left)-height(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};