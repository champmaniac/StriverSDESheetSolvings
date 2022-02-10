class Solution
{
public:
    // root : the root Node of the given BST
    // target : the target sum
    void inorderTrav(Node *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;
        inorderTrav(root->left, inorder);
        inorder.push_back(root->data);
        inorderTrav(root->right, inorder);
    }
    int isPairPresent(struct Node *root, int target)
    {
        //add code here.
        vector<int> inorder;
        inorderTrav(root, inorder);
        int n = inorder.size();
        for (int i = 0, j = n - 1; i < j;)
        {
            int sum = inorder[i] + inorder[j];
            if (sum == target)
                return 1;
            else if (sum > target)
                j--;
            else
                i++;
        }
        return 0;
    }
};