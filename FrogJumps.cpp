#include <bits/stdc++.h>


// Space optimzed
// TC O(N) SC O(1)

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int prev = 0;
    int prev2 = 0;
    for (int ind = 1; ind < n; ind++)
    {
        int left = prev + abs(heights[ind] - heights[ind - 1]);
        int right = INT_MAX;
        if (ind > 1)
            right = prev2 + abs(heights[ind] - heights[ind - 2]);
        int cur_i = min(left, right);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}


// Tabulation
// TC O(N) SC O(N)

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int ind = 1; ind < n; ind++)
    {
        int left = dp[ind - 1] + abs(heights[ind] - heights[ind - 1]);
        int right = INT_MAX;
        if (ind > 1)
            right = dp[ind - 2] + abs(heights[ind] - heights[ind - 2]);
        dp[ind] = min(left, right);
    }
    return dp[n - 1];
}

// Memoization
// TC O(N) SC O(N) + O(N)

int find(int ind, vector<int> &heights, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int left = find(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = find(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    return dp[ind] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    return find(n - 1, heights, dp);
}