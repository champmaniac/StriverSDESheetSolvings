class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
        // base case
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        int maxi=INT_MIN;
        int curMaxi;
        while(!q.empty()){
            curMaxi=0;
            int n = q.size();
            while(n--){
                Node* p = q.front();
                curMaxi+=p->data;
                q.pop();
                
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            if(curMaxi>maxi) maxi=curMaxi;
        }
        return maxi;
    }
};