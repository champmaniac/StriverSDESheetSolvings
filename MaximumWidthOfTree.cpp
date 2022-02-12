// Same as Level Order Traversal.cpp just with a slight change
class Solution
{
public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node *root)
    {

        // Your code here
        if (root == NULL)
            return 0;
        int width = 0;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            width = max(width, n);
            for (int i = 0; i < n; i++)
            {
                Node *node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
        }
        return width;
    }
};