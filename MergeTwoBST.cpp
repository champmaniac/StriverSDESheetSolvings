class Solution
{
public:
    //Function to return a list of integers denoting the node
    //values of both the BST in a sorted order.
    void inOrder(Node *root, vector<int> &v)
    {
        if (!root)
            return;
        inOrder(root->left, v);
        v.push_back(root->data);
        inOrder(root->right, v);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        //Your code here
        vector<int> v1, v2;
        inOrder(root1, v1);
        inOrder(root2, v2);
        v1.insert(v1.end(), v2.begin(), v2.end());
        sort(v1.begin(), v1.end());
        return v1;
    }
};