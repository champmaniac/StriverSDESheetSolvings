// Backtracking
// TC O(2^N) SC O(N*2^N)
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

vector<vector<int>> FindAllSubsets(int n, vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> temp;
    subSetFinder(0,temp,ans,arr);
    return ans;
}