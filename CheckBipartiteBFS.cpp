// TC O(N+E)=O(N) SC O(N+E)=O(N)

#include <bits/stdc++.h>
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size();
	vector<vector<int>> graph(n);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(edges[i][j]){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	vector<int> color (n,-1);

	// marking the color of the root 0

	for(int i=0;i<n;i++){
		if(color[i]!=-1)
		{
			continue;
		}
		color[i]=0;
		

		queue<int> q;
		q.push(i);

		int c=0;
		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(int nbr :graph[node]){
				if(color[nbr]!=-1 && color[nbr]==color[node])
					return false;
				else if(color[nbr]==-1)
				{
					color[nbr]=!color[node];
					q.push(nbr);
				}
			}
			c=!c;
		}
	}
	return true;
}



// Another method by creating a function bfs

bool bfs(int src, vector<vector<int>> &graph,vector<int> &color){
        color[src]=1;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto it: graph[u]){
                if(color[it]==-1)
                {
                    color[it]=!color[u];
                    q.push(it);
                }
                else if(color[it]==color[u]) return false;
            }
        }
        return true;
    }
bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1)
                if(!bfs(i,graph,color)) return false;
        }
        return true;
    }