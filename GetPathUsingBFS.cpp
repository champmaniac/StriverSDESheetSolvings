#include<bits/stdc++.h>
vector<int> getPath(int V, int E, vector<int> a, vector<int> b, int v1, int v2) {
    // Vector to store the parent of all nodes
    vector<int> par(V,-1);
    // Map of vectors to store all the edges
    unordered_map<int,vector<int>> graph;
    for(int i=0;i<a.size();i++){
        graph[a[i]].push_back(b[i]);
        graph[b[i]].push_back(a[i]);
    }
    // final ans
    vector<int> ans;
    // check if the first node is the last node then return first node only
    if(v1==v2){
        ans.push_back(v2);
        return ans;
    }

    queue<int> q;

    // BFS
    q.push(v1);
    while(!q.empty()){
        int t =q.front();
        q.pop();
        for(int i=0;i<graph[t].size();i++){
            int curr = graph[t][i];

            // Avoid revisiting the nodes
            if(curr == v1)
                continue;
            if(par[curr]!=-1)
                continue;
            par[curr]=t;
            q.push(curr);
        }
    }

    int k =v2;
    while(k!=-1)
    {
        ans.push_back(k);
        k=par[k];
    }

    vector<int> nPass;
    if(ans[ans.size()-1]!=v1)
        return nPass;
    return ans;
}
