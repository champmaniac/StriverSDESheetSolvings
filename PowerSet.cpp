// Brute Force
// TC O(N*(2^N)) SC O(N*(2^N))

vector<vector<int>> pwset(vector<int>&arr)
{
    //Write your code here
    int n = arr.size();
    vector<vector<int>> ans={{}};
    for(int i=0;i<n;i++){
        int ele = arr[i];
        int len = ans.size();

        for(int j=0;j<len;j++){
            vector<int> temp=ans[j];

            temp.push_back(ele);
            ans.push_back(temp);
        }
    }
    return ans;
}