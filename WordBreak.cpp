// Brute Force
// TC O(2^N) SC O(N)
#include <unordered_set>
unordered_set<string> hashSet;
bool wordBreakHelper(string s)
{
    int len = s.size();
    if(len==0)
        return true;

    for(int i=1;i<=len;i++)
    {
        if(hashSet.find(s.substr(0,i))!=hashSet.end() and wordBreakHelper(s.substr(i,len-i))){
            return true;
        }
    }
    return false;

}

bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    hashSet.clear();

    for(string s:arr)
    {
        hashSet.insert(s);
    }
    return wordBreakHelper(target);
}

// Optimzed using Top down(Memoization) approach
// TC O(N^2) SC O(N)

#include<unordered_set>
// declare hashset
unordered_set<string> hashSet;

bool wordBreakHelper(string &s, int start , vector<int>& dp)
{   // Base case
    if(start==s.size())
        return dp[start]=1;
    //If result is already calculated then return it
    if(dp[start]!=-1)
        return dp[start];
    // Return a loop from 1 to length of the target string
    for(int i=start+1;i<=s.size();i++)
    {
        if(hashSet.find(s.substr(start,i-start))!=hashSet.end()){
            if(wordBreakHelper(s,i,dp))
                return dp[start]=1;
        }
    }
    return dp[start]=0;
}

bool wordBreak(vector < string > & arr, int n, string & target) {
    // clear hashset for current test cases
    hashSet.clear();
    // insert all strings of arr in the hashset
    for(string s:arr)
    {
        hashSet.insert(s);
    }
    // creating a dp array of size target.size() initialized with -1
    vector<int> dp (target.size()+1,-1);
    return wordBreakHelper(target,0,dp);
}