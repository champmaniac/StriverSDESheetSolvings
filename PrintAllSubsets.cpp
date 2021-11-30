// Backtracking
// TC O(N*2^N) SC O(N*2^N)
void subSetFinder(int i,vector<int>&temp,vector<vector<int>> &ans,vector<int> &arr)
{
    if(i==arr.size()){
        if(temp.size()>0)
            ans.push_back(temp);
        return;
    }

    temp.push_back(arr[i]);
    subSetFinder(i+1,temp,ans,arr);
    temp.pop_back();
    subSetFinder(i+1,temp,ans,arr);
}

void printAllSubsets(int n, vector<int> &arr){
    // Write your code here
    // 2D vector to store answer
    vector<vector<int>> ans;
    vector<int> temp;
    subSetFinder(0,temp,ans,arr);
    for(int i=0;i<ans.size();i++)
    {
        sort(ans[i].begin(),ans[i].end());
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}