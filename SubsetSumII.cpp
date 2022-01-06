class Solution {
private:
    void helper(int ind,vector<int>&nums,vector<vector<int>> &ans,vector<int>&ds){
        ans.push_back(ds);
        int n = nums.size();
        for(int i=ind;i<n;i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            helper(i+1,nums,ans,ds);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        helper(0,nums,ans,ds);
        return ans;
    }
};