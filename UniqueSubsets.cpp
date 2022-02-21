class Solution
{
    public:
    //Function to find all possible unique subsets.
    void findSubset(int ind,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds){
        int n = arr.size();
        ans.push_back(ds);
        for(int i=ind;i<n;i++){
            if(i!=ind && arr[i]==arr[i-1]) continue;
            ds.push_back(arr[i]);
            findSubset(i+1,arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(),arr.end());
        findSubset(0,arr,ans,ds);
        return ans;
    }
};