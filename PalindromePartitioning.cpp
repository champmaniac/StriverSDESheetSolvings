// Backtracking /Recursion
// TC O(N) SC O(N)

bool isPalindrome(string s, int start,int end)
{
    while(start<=end)
    {
        if(s[start++]!=s[end--])
            return false;
    }
    return true;
}
void partitionHelper(int idx, string &s,vector<string>&path,vector<vector<string>> &ans){
    int n = s.size();
    if(idx==n){
        ans.push_back(path);
        return;
    }

    for(int i=idx;i<n;i++){
        if(isPalindrome(s,idx,i)){
            path.push_back(s.substr(idx,i-idx+1));
            partitionHelper(i+1,s,path,ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> path;
    partitionHelper(0,s,path,ans);
    return ans;
}