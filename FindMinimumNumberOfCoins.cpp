// Greedy Approach
// TC O(N*Amount) SC O(1)
int findMinimumCoins(int amount) 
{
    // Write your code here
    int deno[] = {1,2,5,10,20,50,100,500,1000};
    int n =9;
    int Mincount=0;

    for(int i=n-1;i>=0;i--)
    {
        while(amount>=deno[i])
        {
            amount-=deno[i];
            Mincount++;
        }
    }
    return Mincount;
}


// Optimzed Greedy Approach
// TC O(N) SC O(1)

int findMinimumCoins(int amount) 
{
    // Write your code here
    int deno[] = {1,2,5,10,20,50,100,500,1000};
    int n =9;
    int Mincount=0;

    for(int i=n-1;i>=0;i--)
    {
        while(amount>=deno[i])
        {
            Mincount+=amount/deno[i];
            amount%=deno[i];
        }
    }
    return Mincount;
}