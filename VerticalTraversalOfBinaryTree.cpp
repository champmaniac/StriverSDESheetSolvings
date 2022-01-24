class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    void preOrder(Node* root,int vert,int level,map<int,map<int,vector<int>>> &mp){
        if(!root) return;
        
        mp[vert][level].push_back(root->data);
        preOrder(root->left,vert-1,level+1,mp);
        preOrder(root->right,vert+1,level+1,mp);
    }
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,map<int,vector<int>>> mp;
        preOrder(root,0,0,mp);
        vector<int> ans;
        
        for(auto i:mp){
            for(auto j:i.second){
                for(auto q:j.second){
                    ans.push_back(q);
                }
            }
        }
        return ans;
    }
};