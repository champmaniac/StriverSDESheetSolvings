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