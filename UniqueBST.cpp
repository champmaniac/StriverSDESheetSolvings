class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int N) 
    {
        // Your code here
        long long mod = 1e9+7;
        long long dp[N+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<N+1;i++){
            long long sum=0;
            for(int j=0,k=i-1;j<i,k>=0;j++,k--){
                sum=(sum+(dp[j]*dp[k])%mod)%mod;
            }
            dp[i]=sum;
        }
        return dp[N]%mod;
    }
};