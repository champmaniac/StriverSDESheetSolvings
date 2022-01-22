class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src, vector<int> adj[], vector<bool> &vis, vector<int> &stack)
    {
        stack[src] = true;
        if (!vis[src])
        {
            vis[src] = true;
            for (auto it : adj[src])
            {
                if (!vis[it] && dfs(it, adj, vis, stack))
                    return true;
                if (stack[it])
                    return true;
            }
        }
        stack[src] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<bool> vis(V, 0);
        vector<int> stack(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && dfs(i, adj, vis, stack))
            {
                return true;
            }
        }
        return false;
    }
};