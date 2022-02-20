int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n =nums.size();
    int prev = nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take = nums[i];
        if(i>1)take+=prev2; 

        int notTake = 0+prev;
        int cur_i = max(take,notTake);
        prev2=prev;
        prev=cur_i;  
    }
    return prev;
}