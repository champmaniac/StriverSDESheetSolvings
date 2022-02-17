class Solution
{
public:
    // Function should return all the ancestor of the target node
    bool solve(Node *root, int target, vector<int> &v)
    {
        if (root == NULL)
            return false;
        v.push_back(root->data);
        if (root->data == target)
            return true;
        bool lh = solve(root->left, target, v);
        bool rh = solve(root->right, target, v);
        if (lh || rh)
            return true;
        v.pop_back();
        return false;
    }
    vector<int> Ancestors(struct Node *root, int target)
    {
        // Code here
        vector<int> v;
        bool l = solve(root, target, v);
        v.pop_back();
        reverse(v.begin(), v.end());
        return v;
    }
};