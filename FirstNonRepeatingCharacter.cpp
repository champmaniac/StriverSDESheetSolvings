// Hashing algorithm: Hash table
// TC `O(N)` SC `O(N)`
string find(string s) {
    //code here
    unordered_map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    string ans="";
    for(int i=0;i<s.size();i++){
        if(mp.find(s[i])->second==1){
            ans+=s[i];
            break;
        }
    }
    if(ans.size()==0) return "-1";
    return ans;
}