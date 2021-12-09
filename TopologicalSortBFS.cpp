// TC O(N+E) SC O(N)
 
vector<int> topoSort(int N, vector<int> adj[]){
	// Queue to push the data in FIFO
	queue<int> q;
	// Put the indegree
	vector<int> indegree(N,0);
	// Count the initial indegree of each node
	for(int i=0;i<N;i++){
		for(auto it:adj[i])
			indegree[it]++;
	}
	// If initially indegree is 0 then just push them into the queue
	for(int i=0;i<N;i++){
		if(indegree[i]==0)
			q.push(i);
	}
	// Take a vector topo to store the topological sort
	vector<int> topo;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		topo.push_back(node);
		// Decreasing indegree by one after taking out each node 
		for(auto &it:adj[node]){
			indegree[it]--;
			// And then check if the indegree of the node becomes 0 if yes then add it in the queue
			if(indegree[it]==0)
				q.push(it);
		}
	}
	return topo;
} 

// We decrease the indegree everytime we find a node since we are just removing the edge from u to v. 

