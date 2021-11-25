// Brute Force TC O(N^N) SC O(1)
int LongestSubsetWithZeroSum(vector < int > arr) {
  int maxi =0;
  int n = arr.size();
  for(int i=0;i<n;i++)
  {
    int sum =0;
    for(int j=i;j<n;j++)
    {
      sum+=arr[j];
      if(sum==0)
        maxi=max(maxi,j-i+1);
    }
  }
  return maxi;
}

// Can we do it single traversal? Yes ! below is the optimzed version
// Optimized Approach TC O(N) SC O(N)

#include <unordered_map>
int LongestSubsetWithZeroSum(vector < int > arr) {
  unordered_map<int,int> mp;
  int maxi=0,sum=0;
  int n = arr.size();
  for(int i=0;i<n;i++)
  {
    sum+=arr[i];
    if(sum==0)
      maxi=i+1;
    else
    {
      if(mp.find(sum)!=mp.end()){
        maxi=max(maxi,i-mp[sum]);
      }
      else
        mp[sum]=i;
    }

  }
  return maxi;
}