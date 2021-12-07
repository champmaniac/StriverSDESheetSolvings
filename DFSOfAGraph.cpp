void dfs(int node, vector<int> &vis, vector<int> &storeDfs, vector<int> adj[]){
        storeDfs.push_back(node);
        vis[node]=1;
        for(auto &it: adj[node]){
            if(!vis[it])
                dfs(it,vis,storeDfs,adj);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> storeDfs;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
                dfs(i,vis,storeDfs,adj);
        }
        return storeDfs;
    }