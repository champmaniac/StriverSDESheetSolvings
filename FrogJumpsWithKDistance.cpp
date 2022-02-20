#include <bits/stdc++.h>


// Recursion

int find(int ind,vector<int> &heights,int k)
{
    if (ind == 0)
        return 0;
    int minSteps=INT_MAX;
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
            int jump = find(ind-j,heights,k) + abs(heights[ind] - heights[ind - j]);
            minSteps=min(minSteps,jump);
        }
    }
    return jump;
}
int frogJump(int n, vector<int> &heights,int k)
{
    // Write your code here.
    return find(n - 1,heights,k);
}
