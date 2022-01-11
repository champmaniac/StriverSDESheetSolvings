// TC O((3N^2))
class Solution
{
public:
    void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string move, vector<vector<int>> &vis)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(move);
            return;
        }
        // string dir="DLRU"

        //downward
        if (i + 1 < n && !vis[i + 1][j] && m[i + 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i + 1, j, m, n, ans, move + 'D', vis);
            vis[i][j] = 0;
        }

        //left
        if (j - 1 >= 0 && !vis[i][j - 1] && m[i][j - 1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j - 1, m, n, ans, move + 'L', vis);
            vis[i][j] = 0;
        }

        //Right
        if (j + 1 < n && !vis[i][j + 1] && m[i][j + 1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j + 1, m, n, ans, move + 'R', vis);
            vis[i][j] = 0;
        }

        //upward
        if (i - 1 >= 0 && !vis[i - 1][j] && m[i - 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i - 1, j, m, n, ans, move + 'U', vis);
            vis[i][j] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        // int di={-1,0,0,1};
        // int dj={0,1,-1,0};
        if (m[0][0] == 1)
            solve(0, 0, m, n, ans, "", vis);
        return ans;
    }
};

// Optimized Approach
class Solution
{
public:
    void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dj[])
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for (int ind = 0; ind < 4; ind++)
        {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];

            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && m[nexti][nextj] == 1)
            {
                vis[i][j] = 1;
                solve(nexti, nextj, m, n, ans, move + dir[ind], vis, di, dj);
                vis[i][j] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, +1, 0};
        if (m[0][0] == 1)
            solve(0, 0, m, n, ans, "", vis, di, dj);
        return ans;
    }
};
