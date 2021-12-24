// Using Stack
// TC O(1) SC O(H)
#include<stack>
class BSTiterator
{
public:
    stack<TreeNode<int>*> st;
    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode<int> *temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }
    void pushAll(TreeNode<int>* root){
        // for(;root!=NULL; st.push(root), root=root->left); // any of the loops will work
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
};