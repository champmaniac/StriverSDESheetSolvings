class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        vector<int> res;
        int len = v.size();
        for(int i=0;i<k;i++){
            res.push_back(v[len-1].second);
            len--;
        }
        return res
    }
};
