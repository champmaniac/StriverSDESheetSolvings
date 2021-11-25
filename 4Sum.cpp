// Brute Force TC O(N^4) SC O(1)
#include<bits/stdc++.h>
string fourSum(vector<int> arr, int target, int n) {
    for(int i=0;i<n-3;++i)
    {
        for(int j=i+1;j<n-2;++j)
        {
            for(int k=j+1;k<n-1;++k)
            {
                for(int l=k+1;l<n;++l)
                {
                    if(arr[i]+arr[j]+arr[k]+arr[l]==target)
                        return "Yes";
                }
            }
        }
    }
    return "No";
}

// Optimized using hashmap TC O(N^2) SC O(N^2)
#include<bits/stdc++.h>
bool commonIdx(pair<int,int> p1, pair<int,int> p2){
    return p1.first==p2.first || p1.first==p2.second || p1.second==p2.first || p1.second==p2.second;
}
string fourSum(vector<int> arr, int target, int n) {
    unordered_map<int,pair<int,int>> mp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            mp[arr[i]+arr[j]]={
                i,
                j
            };
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            int requiredSum = target-(arr[i]+arr[j]);

            if(mp.find(requiredSum)!=mp.end() && !commonIdx(mp[requiredSum],{
                i,
                j

            }))
            {
                return "Yes";
            }
        }
    }
    return "No";
}
