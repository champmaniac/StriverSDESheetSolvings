class Solution{            // TC O(2^N) SC O(1)
public:
    int catalan(int n){
        if(n<=1) return 1;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=catalan(i)*catalan(n-i-1);
        }
        return ans;
    } 
    int count(int N){
        // code here
        return catalan(N/2);
    }
};