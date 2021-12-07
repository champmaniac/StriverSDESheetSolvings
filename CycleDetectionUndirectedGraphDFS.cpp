// TC O(N+E)=O(N) SC O(N+E)=O(N)

bool isCycle(int node,vector<vector<int>>&graph,vector<bool> &visited, int parent){
    visited[node]=true;
    for(int adj:graph[node]){
        if(visited[adj]==false){
            if(isCycle(adj,graph,visited,node)==true)
                return true;
        }
        else if(adj!=parent)
            return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> graph(n+1,vector<int>());
    for(int i=0;i<m;i++){
        graph[edges[i][1]].push_back(edges[i][0]);
        graph[edges[i][0]].push_back(edges[i][1]);
    } 

    vector<bool> visited(n+1,false);

    for(int i=1;i<=n;i++){
        if(!visited[i])
        {
            if(isCycle(i,graph,visited,-1)==true)
                return "Yes";
        }
    }
    return "No";
}
