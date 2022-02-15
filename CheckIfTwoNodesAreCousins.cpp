void helper(Node *root, int x, int level, pair<Node *, int> &dp)
{
    if (!root)
        return;
    if (root->left && root->left->data == x)
    {
        dp = {root, level};
    }
    if (root->right && root->right->data == x)
    {
        dp = {root, level};
    }
    helper(root->left, x, level + 1, dp);
    helper(root->right, x, level + 1, dp);
}
bool isCousins(Node *root, int a, int b)
{
    //add code here.
    pair<Node *, int> a1;
    pair<Node *, int> b1;
    helper(root, a, 1, a1);
    helper(root, b, 1, b1);
    if (a1.first != b1.first && a1.second == b1.second)
        return 1;
    return 0;
}