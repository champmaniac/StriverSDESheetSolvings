// TC(4 aplha) or O(4) SC O(N)


int parent[100000];
int rank[100000];

void makeSet(){
	for(int i=0;i<=n;i++){
		parent[i]=i;
		rank[i]=0;	
	}
}

int findPar(int node){
	if(node==parent[node])
		return node;
	// return findPar(parent[node]); // normal 7->6->4>->3 3's parent 4,4's parent 6 and so on so make each child point directly to parent we use path compression
	return parent[node]=findPar(parent[node]); // by path compression
}

void union(int u,int v){
	u =findPar(u);
	v =findPar(v);
	if(rank[u]<rank[v])
		parent[u]=v;
	else if(rank[u]>rank[v])
		parent[v]=u;
	else{
		parent[v]=u;
		rank[u]++;
	}

}

void main(){
	makeSet();
	int m;
	cin>>m;
	while(m--){
		int u,v;
		union(u,v);
	}
	// to check if 2 and 3 are from the same component or not
	if(findPar(2)!=findPar(3)){
		cout<<"Different Componenet"<<endl;
	}
	else
		cout<<"Same Componenet"<<endl;
}