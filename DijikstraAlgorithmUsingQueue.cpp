class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,INT_MAX);
        queue<int> q;
        dist[S]=0;
        q.push(S);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(vector<int> neighbour :adj[node]){
                int nextNode = neighbour[0];
                int nextDist = neighbour[1];
                if(dist[node]+nextDist<dist[nextNode]){
                    dist[nextNode]=dist[node]+nextDist;
                    q.push(nextNode);
                }
            }
        }
        return dist;
    }
};