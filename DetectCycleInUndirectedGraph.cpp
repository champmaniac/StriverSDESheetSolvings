class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[], int src, vector<bool> &vis, int parent)
    {
        vis[src] = true;
        for (auto it : adj[src])
        {
            if (!vis[it])
            {
                if (dfs(adj, it, vis, src))
                    return true;
            }
            else if (it != parent)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(adj, i, vis, -1))
                    return true;
            }
        }
        return false;
    }
};