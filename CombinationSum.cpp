// TC O(2^t*k) SC O(k*x) wher x is the number of the combinations
class Solution {
public:
    void findCombination(int ind, int target,vector<int>& arr,vector<vector<int>> &ans,vector<int> &ds){
        int n = arr.size();
        if(ind==n)
        {
            if(target==0)
                ans.push_back(ds);
            return;
        }
        // pick up the element
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findCombination(ind,target-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        // not pick up the element
        findCombination(ind+1,target,arr,ans,ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> ds;
        findCombination(0,target,candidates,ans,ds);
        return ans;
    }
};