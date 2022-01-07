// Approach 1
// TC O(n!*n) SC O(N)+O(N)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++) freq[i]=0;
        recurPermute(ds,nums,ans,freq);
        return ans;
    }
    void recurPermute(vector<int> &ds,vector<int> &nums,vector<vector<int>> &ans,int freq[]){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                recurPermute(ds,nums,ans,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }      
    }
};

// Approach 2
// TC O(n!*n) SC O(N)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0,nums,ans);
        return ans;
    }
    void recurPermute(int ind, vector<int> &nums,vector<vector<int>> &ans){
        if(ind ==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=0;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            recurPermute(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
        
    }
};
