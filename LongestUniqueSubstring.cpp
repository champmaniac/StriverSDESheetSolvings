// Optimized Hashmap approach TC O(N) SC O(N)

#include<unordered_map>
int uniqueSubstrings(string input)
{
    int n = input.size();
    int start =0, res=0;
    unordered_map<char,int> mp;
    for(int i=0;i<n;i++)
    {
        if(mp.find(input[i])!=mp.end() && mp[input[i]]>=start)
        {
            start = mp[input[i]]+1;
        }
        mp[input[i]]=i;
        res= max(res,i-start+1);
    }
    return res;
}