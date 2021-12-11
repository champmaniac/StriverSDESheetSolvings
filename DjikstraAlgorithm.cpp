void dijkstra(int v, int src, vector<pair<int,int>> &adj[]){
	vector<int> dist(v,INT_MAX);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	dist[src]=0;
	pq.push(make_pair(0, src));

	while(!pq.empty()){
		int node = pq.top().second;
		int wt = pq.top().first; // the weight or the distance travelled from src to node (dist,node) or (wt,node)
		pq.pop();
		for(auto &it:adj[node]){
			if(dist[node]+it.second<dist[it.first]){
				dist[it.first]=dist[node]+it.second;
				pq.push(make_pair(dist[it.first]),it.first);
			}
		}
	}

	for(int i=0;i<v;i++){
		cout<<dist[i]<<endl;
	}
}


int main(){
	cout<<"Enter the number of vertices and no. of nodes: ";
	int n, m, src;
	cin>>n>>m;

	//this is  undirected weighted graph
	cout<<"Enter all the edges, i.e, start and end of node and their weight: "<<endl;
	vector<pair<int, int>> adj[n];
	for(int i=0; i<m; i++){
		int u, v, wt;
		cin>>u>>v>>wt;
		adj[u].push_back(make_pair(v, wt));
		adj[v].push_back(make_pair(u, wt));
	}
	cout<<"Enter the source of the graph: ";
	cin>>src;
	dijkstra(n, src, adj);
	return 0;
}
