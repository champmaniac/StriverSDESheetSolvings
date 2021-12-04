// Brute Force
// TC O(N^2) SC O(1)
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> ans(n);
    //For every element
    for(int i=0;i<n;i++)
    {
        int next =-1;

        // find its next greater element
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]<arr[j])
            {
                next = arr[j];
                break;
            }
        }
        ans[i]=next;
    }
    return ans;
}

// Optimized approach
// TC O(N) SC O(N)
#include <bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> ans(n);
    stack<int> s;

    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty()&&s.top()<=arr[i])
        {
            s.pop();
        }

        if(s.empty())
            ans[i]=-1;
        else
            ans[i]=s.top();
        a.push(arr[i]);
    }
    return ans;
}