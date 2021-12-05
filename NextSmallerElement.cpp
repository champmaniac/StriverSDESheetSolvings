// Brute force
// TC O(N^2) SC O(1)
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        int next=-1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                next=arr[j];
                break;
            }
        }
        ans[i]=next;
    }
    return ans;
}


// Optimized approach using stack
// TC O(N^2) SC O(1)
#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
}