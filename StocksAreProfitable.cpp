// Brute force
// TC O(N^2) SC O(1)
int maximumProfit(vector<int> &prices){

    int n = prices.size();
    int maxProfit=0;

    for(int i=0;i<n-1;i++)
    {
        int buy=prices[i], curMaxProfit =0; 

        for(int j=i+1;j<n;j++)
        {
            curMaxProfit = max(curMaxProfit,(prices[j]-buy));
        }
        maxProfit= max(maxProfit,curMaxProfit);
    }
    return maxProfit;
}

// Optimized Brute force
// TC O(N) SC O(1)
int maximumProfit(vector<int> &prices){

    // Variables to store the buying price and maximum profit
    int buy = prices[0],maxProfit = 0;
    int n = prices.size();

    // Iterating over the array
    for(int i = 1; i < n; i++){

        /*
            If current price is less than buying price
            we will update buying price as the current price.
        */
        if(prices[i] < buy){
            buy = prices[i];
        }

        /*
            Else if selling at this price is more profitable,
            then we will update out maximum profit.
        */
        else if( (prices[i] - buy) > maxProfit){
            maxProfit = prices[i] - buy;
        }
    }
    return maxProfit;
}