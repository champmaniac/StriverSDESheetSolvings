void inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
float findMedian(struct Node *root)
{
    //Code here
    vector<int> ans;
    inorder(root, ans);
    int n = ans.size();
    if (n % 2 == 0)
        return (((float)ans[n / 2 - 1] + (float)ans[(n / 2) + 1 - 1]) / 2);
    else
        return ans[((n + 1) / 2) - 1];
}