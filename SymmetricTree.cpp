class Solution
{
public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetricHelper(Node *left, Node *right)
    {
        if (!left || !right)
            return left == right;
        if (left->data != right->data)
            return false;

        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }
    bool isSymmetric(struct Node *root)
    {
        // Code here
        return root == NULL || isSymmetricHelper(root->left, root->right);
    }
};