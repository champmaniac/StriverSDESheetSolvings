#include <bits/stdc++.h>
bool checkCycle(int node,int visited[],int dfsVisited[], vector<int> adj[]){
    visited[node]=1;
    dfsVisited[node]=1;

    for(auto it:adj[node]){
        if(!visited[it]){
            if(checkCycle(it,visited,dfsVisited,adj)) return true;
        }
        else if(dfsVisited[it]) return true;
    }
    dfsVisited[node]=0;
    return false;
}

bool cycle(int v,vector<int> adj[]){
    int visited[v];
    int dfsVisited[v];

    memset(visited,0,sizeof visited);
    memset(dfsVisited,0,sizeof dfsVisited);

    for(int i=0;i<v;i++){
        if(visited[i]==0){
            if(checkCycle(i,visited,dfsVisited,adj)) return true;    
        }

    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> adj[];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }
    if(cycle(n,adj)) cout<<"Yes";
    else
        cout<<"No";
    return 0;
}