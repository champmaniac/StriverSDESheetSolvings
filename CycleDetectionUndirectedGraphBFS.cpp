#include <bits/stdc++.h>
bool isCycle(int src,vector<vector<int>>&graph,vector<bool> &visited){
    queue<pair<int,int>> q;
    visited[src]=1;
    q.push({src,-1});

    while(!q.empty()){
        int node= q.front().first;
        int par = q.front().second;
        q.pop();

        for(auto it:graph[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push({it,node});
            }
            else if(it!=par)
                return true;
        }
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
            if(isCycle(i,graph,visited)==true)
                return "Yes";
        }
    }
    return "No";
}
