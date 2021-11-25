#include<bits/stdc++.h>
string fourSum(vector<int> nums, int target, int n) {
    sort(nums.begin(),arr.end());
    set<vector<int>> st;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int x = (long long) target-(long long)nums[i]-(long long)nums[j]-(long long)nums[k];
                if(binary_search(nums.begin()+k+1,nums.end(),x))
                {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    v.push_back(x);
                    sort(v.begin(),v.end());
                    st.insert(v);
                }
            }
        }
    }
    vector<vector<int>> res(st.begin(),st.end());
    return
}
