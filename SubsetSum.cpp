class Solution
{
private:
    void solve(int i,vector<int> &arr,int n,int sum,vector<int>&ans){
        if(i==n){
            ans.push_back(sum);
            return;
        }
        // pick the element
        solve(i+1,arr,n,(sum+arr[i]),ans);
        // not pick the element
        solve(i+1,arr,n,sum,ans);
        return;
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        solve(0,arr,N,0,ans);
        return ans;
        
    }
};