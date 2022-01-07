class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == NULL)
                s.append("#,");
            else
                s.append(to_string(cur->val) + ',');
            if (cur != NULL)
            {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int n = data.size();
        if (n == 0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
                node->left = NULL;
            else
            {
                TreeNode *leftnode = new TreeNode(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }
            getline(s, str, ',');
            if (str == "#")
                node->right = NULL;
            else
            {
                TreeNode *rightnode = new TreeNode(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Alternative Easy version
class Solution
{
public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> vec;
    // inorder Traversal
    void help(Node *root)
    {
        if (!root)
            return;
        help(root->left);
        vec.push_back(root->data);
        help(root->right);
    }
    vector<int> serialize(Node *root)
    {
        //Your code here
        help(root);
        return vec;
    }

    //Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
        //Your code here
        struct Node *newroot = new Node(-1);
        Node *temp = newroot;
        int n = A.size();
        for (int i = 0; i < n; i++)
        {
            temp->right = new Node(A[i]);
            temp = temp->right;
        }
        return newroot->right;
    }
};