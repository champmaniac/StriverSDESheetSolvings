void bfs(int src, vector<int>&vis, vector<int> &storeBfs, vector<int> adj[]){
    queue<int> q;
    q.push(src);
    vis[src]=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        storeBfs.push_back(node);
        for(auto &it: adj[node]){
            if(!vis[it])
            {
                q.push(it);
                vis[it]=1;
            }
        }
    }
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> storeBfs;
    vector<int> vis(V,0);

    for(int i=0;i<V;i++){
        if(!vis[i])
            bfs(i,vis,storeBfs,adj);
    }
    return storeBfs;
}