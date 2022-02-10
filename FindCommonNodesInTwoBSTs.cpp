class Solution
{
public:
    //Function to find the nodes that are common in both BST.
    void check(Node *root, unordered_set<int> &s, vector<int> &v)
    {
        if (root == NULL)
            return;
        check(root->left, s, v);
        if (s.find(root->data) != s.end())
            v.push_back(root->data);
        check(root->right, s, v);
    }
    void store(Node *root, unordered_set<int> &s)
    {
        if (root == NULL)
            return;
        s.insert(root->data);
        store(root->left, s);
        store(root->right, s);
    }
    vector<int> findCommon(Node *root1, Node *root2)
    {
        //Your code here
        unordered_set<int> s;
        vector<int> v;
        store(root1, s);
        check(root2, s, v);
        return v;
    }
};