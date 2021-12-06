// Using Queue
// TC O(V+E) SC O(V^2)
#include<bits/stdc++.h>
#include<queue>
void BFSHelper(vector<vector<int>> &adj_list,int source,vector<bool> &vis,vector<int>& res){
    queue<int> q;
    vis[source]=true;
    q.push(source);


    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        res.push_back(front);

        for(int i=0;i<adj_list.size();i++){
            if(adj_list[front][i]==1 && !vis[i])
            {
                vis[i]=true;
                q.push(i);
            }
        }
    }
}

vector<vector<int>> adjacency_list(int vertex, vector<pair<int,int>> &edges){
    vector<vector<int>> adj_list(vertex);
    for(int i=0;i<vertex;i++){
        adj_list[i]=vector<int>(vertex);
        for(int j=0;j<vertex;j++)
            adj_list[i][j]=0;
    }
    int size = edges.size();
    for(int i=0;i<size;i++){
        adj_list[edges[i].first][edges[i].second]=1;
        adj_list[edges[i].second][edges[i].first]=1;
    }
    return adj_list;
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<vector<int>> adj_list = adjacency_list(vertex,edges);
    int adj_size = adj_list.size();
    vector<bool> vis(adj_size);

    for(int i=0;i<vertex;i++){
        vis[i]=false;
    }
    vector<int> res;

    for(int i=0;i<adj_size;i++){
        if(!vis[i]){
            BFSHelper(adj_list,i,vis,res);
        }
    }
    return res;
}