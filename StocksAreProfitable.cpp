/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where N is the size of the array.
*/

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