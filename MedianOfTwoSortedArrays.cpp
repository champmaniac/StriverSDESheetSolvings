// Brute Force
// TC (NlogN) SC O(N)
#include<bits/stdc++.h>
double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    vector<int> ds;
        for(int i=0;i<a.size();i++)
            ds.push_back(a[i]);
        for(int i=0;i<b.size();i++)
            ds.push_back(b[i]);
        sort(ds.begin(),ds.end());
        int size = ds.size();
        if(size%2!=0)
            return ds[size/2];
        else
            return (ds[size/2]+ds[size/2-1])/2.00000;
}
