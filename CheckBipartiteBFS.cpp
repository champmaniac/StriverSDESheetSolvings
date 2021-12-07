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