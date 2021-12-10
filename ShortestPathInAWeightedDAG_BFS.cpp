void topoSort(int src, vector<int> &st, vector<int> &vis,vector<pair<int,int>> &adj[]){
	vis[src]=1;
	for(auto &it:adj[src]){
		if(!vis[it.first]){
			topoSort(it.first,st,vis,adj);
		}
	}
	st.push(src);
}

void shortestPath(int v,int src vector<pair<int,int>> adj[]){
	vector<int> vis(v,0);
	stack<int> st;
	for(int i=0;i<v;i++){
		if(!vis[i]){
			topoSort(i,st,vis,adj);
		}
	}

	int dist[v];
	for(int i=0;i<v;i++){
		dist[i]=INT_MAX;
	}
	dist[src]=0;
	while(!st.empty()){
		int node = st.top();
		st.pop();
		if(dist[node]!=INT_MAX){
			for(auto &it: adj[node]){
				if(dist[node]+it.second()<dist[it.first])
					dist[it.first]=dist[node]+it.second;
			}
		}
	}

	for(int i=0;i<v;i++){
		if(dist[i]==INT_MAX)? cout<<"Infinity": cout<<dist[i]<<endl;
	}
}