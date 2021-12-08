#include <bits/stdc++.h>

void topologicalSortHelper(vector<vector<int>> &adj,vector<bool> &visited,stack<int>&st,int src){
    // Mark the current vertex visited
    visited[src]=true;
    // Iterate over adjacent vertices
    for(int node:adj[src]){
        if(!visited[node]){
            topologicalSortHelper(adj,visited,st,node);
        }
    }
    // Pushing vertex in stack afer pushing all it's adjacent vertices.
    st.push(src);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    // Creating adjacency list
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> visited(v);
    stack<int> st;
    // Recursively find the topological sort
    for(int i=0;i<v;i++){
        if(!visited[i])
            topologicalSortHelper(adj,visited,st,i);
    }
    // Store the topological sort of the given graph in res
    vector<int> res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    return res;
}