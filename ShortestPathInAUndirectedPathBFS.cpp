void shortestPath(int v,int src, vector<int> adj[]){
	int dis[v];
	for(int i=0;i<v;i++)
		dis[i]=INT_MAX;

	dis[src]=0;
	queue<int> q;
	q.push(src);

	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto &it:adj[node]){
			if((dis[node]+1)<dis[it]){
				dis[it]=dis[node]+1;
				q.push(it);
			}
		}
	}

	for(int i=0;i<v;i++)
		cout<<dis[i]<<"";

}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> adj[n];

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	shortestPath(n,0,adj);
	return 0;
}