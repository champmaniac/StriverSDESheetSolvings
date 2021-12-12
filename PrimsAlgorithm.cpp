void prims(int v,int src,vector<pair<int,int>>&adj[]){
	// Declare three arrays and initialize them
	int keys[v];
	int parent=[v];
	bool setMST[v];
	for(int i=0;i<v;i++){
		keys[i]=INT_MAX;
		setMST[i]=false;
	}

	// Intialize key of source as o and the parent of source -1
	keys[src]=0;
	parent[src]=-1;


	// Run loop from n-1 because there are n-1 edges only	
	for(int i=0;i<v-1;i++){
		int mini =INT_MAX, index;
		// find the node which have minimum key and is not visited
		for(int i=0;i<v;i++){
			if(keys[i]<mini && setMST[i]==false)
			{
				mini=keys[i];
				index=i; // storing the index of the minimum key
			}
		}
		// at the end mark the node as true in mst
		setMST[index]=true;


		// go to all of its adjacent nodes and find out which oe has the minimum wt and is not added in the mst
		for(auto &it: adj[index]){
			int node = it.first;
			int wt = it.second;
			// update the key if it has the minimum weight and is not added in mst  and update the parent
			if(keys[node]>wt && setMST[node]==false)
			{
				keys[node]=wt;
				parent[node]=index;
			}
		}
	}

	// print the nodes
	for(int i=0;i<v;i++){
		cout<<parent[i]<<"-"<<endl;
	}
}