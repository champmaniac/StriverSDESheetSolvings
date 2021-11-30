// Brute Force 
// TC O(N!) SC O(N!)

void permute(string s, string ans, vector<string> &res)
{
    if(s.size()==0)
    {
        res.push_back(ans);
        return;
    }

    for(int i=0;i<s.size();i++)
    {
        ans+=s[i];

        permute(s.substr(0,i)+s.substr(i+1),ans,res);

        ans.pop_back();
    }
}

string kthPermutation(int n, int k) {
    vector<string> res;
    string s="";

    for(int i=1;i<=n;i++)
    {
        s+=to_string(i);
    }
    permute(s,"",res);
    return res[k-1]; 
}

// Optimized approach
// TC O(N^2) SC O(N)
string kthPermutation(int n, int k) {
    // Write your code here.
    vector<int> number;
    int fact=1;
    for(int i=1;i<n;i++)
    {
        fact=fact*i;
        number.push_back(i);
    }

    number.push_back(n);
    string ans="";
    k=k-1;
    while(true)
    {
        ans=ans+to_string(number[k/fact]);
        number.erase(number.begin()+k/fact);
        if(number.size()==0)
            break;
        k=k%fact;
        fact=fact/number.size();
    }
    return ans;
}
