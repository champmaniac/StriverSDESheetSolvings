bool cycleBFS(int V, vector<int> adj[]){
	queue<int> q;
	vector<int> indegree(V,0);

	for(int i=0;i<V;i++){
		for(auto &it:adj[i]){
			indegree[it]++;
		}
	}

	for(int i=0;i<V;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}

	int count=0;
	vector<int> topo;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		count++;
		topo.push_back(i);
		for(auto &it:adj[node]){
			indegree[it]--;
			if(indegree[it]==0)
				q.push(it);
		}
	}
	if(count==V) return false;
	else return true;
}