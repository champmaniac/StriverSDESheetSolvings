class node{
public:
	int u,v,wt;
	node(int first,int second,int weight){
		u=first;
		v=second;
		wt=weight;
	}
};

bool comp(node a,node b){
	return a.wt<b.wt;
}

int findPar(int u, vector<int>&parent){
	if(parent[u]==u) return u;
	return parent[u] = findPar(parent[u],parent);
}

void union(int u, int v, vector<int>&parent, vector<int>&rank){
	u=findPar(u,parent);
	v=findPar(v,parent);

	if(rank[u]>rank[v]){
		parent[v]=u;
	}
	else if(rank[v]>rank[u]){
		parent[u]=v;
	}
	else if(rank[u]==rank[v]){
		parent[v]=u;
		rank[u]++;
	}
}

int main(){
	int n,m;
	cin>>n>>m;

	vector<node>edges;
	for(int i=0;i<m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		edges.push_back(node(u,v,wt));
	}

	sort(edges.begin(),edges.end());

	vector<int> parent(n);
	for(int i=0;i<n;i++){
		parent[i]=i;
	}

	vector<int> rank(n,0);

	int cost =0;
	vector<pari<int,int> mst;
	for(auto it:edges){
		if(findPar(it.v,parent)!=findPar(it.u,parent)){
			cost+=it.wt;
			mst.push_back({it.u,it.v});
			union(it.u,it.v,parent,rank);
		}
	}

	cout<<"Cost - "<<cost<<endl;
	for(auto it:mst){
		cout<<it.first<<"-"<<it.second<<endl;
	} 
	return 0;
}