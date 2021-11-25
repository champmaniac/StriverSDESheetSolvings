// Brute Force TC O(N*logN) SC O(N*logN+N)= O(N*logN)
#include <bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int res=1,cnt=1;
    sort(arr.begin(),arr.end()); // nlogn
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1]+1)
            cnt++;
        else if(arr[i]>(arr[i-1]+1))
            cnt=1;
        res=max(res,cnt);
    }
    return res;
}


// Optimized approach using hashmap TC O(N) SC O(N)

#include<unordered_set>
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    int maxi =0;
    unordered_set<int> st;
    for(int i=0;i<n;i++)
    {
        st.insert(arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        int prevConsecutiveSeq = arr[i]-1;
        if(st.find(prevConsecutiveSeq)==st.end()){
            int j=arr[i];
            while(st.find(j)!=st.end())
                j++;
            maxi = max(maxi,j-arr[i]);
        }
    }
    return maxi;
}