// Strongly Connected Component (SCC)
// Sort all the nodes in order of the finishing times 
// i.e is done using Topo sort DFS
// TC O(N+E) SC O(N+E)+O(N)+O(N)
void dfs(int node, stack<int>&st,vector<int>&vis,vector<int>&adj[]){
	vis[node]=1;
	for(auto it:adj[node]){
		if(!vis[it])
		{
			dfs(it,st,vis,adj);
		}
	}
	st.push(i);
}

void revDfs(int node,vector<int>&vis,vector<int> transpose[]){
	cout<< node<<" ";
	vis[node]=1;
	for(auto it:transpose[node]){
		if(!vis[it]){
			revDfs(it,vis,transpose);
		}
	}
}

int main(){
	int n,m;
	cin>> n>>m;
	vector<int> adj[n];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}

	stack<int> st;
	vector<int> vis(n,0);
	for(int i=0;i<n;i++){
		if(!vis[i])
		{
			dfs(i,st,vis,adj);
		}
	}

	vector<int> transpose[n];

	for (int i=0;i<n;++i)
	{
		vis[i]=0;
		for(auto &it:adj[i]){
			transpose[it].push_back(i);
		}
	}

	while(!st.empty()){
		int node = st.top();
		st.pop();
		if(!vis[node]){
			cout<< "SCC:";
			revDfs(node,vis,transpose);
			cout<<endl;
		}
	}
	return 0;
}