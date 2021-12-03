// Brute Force
// TC O(N) SC O(1)
int calculateSquare(int num)
{
    // Making the number +ve if it's -ve
    if(num<0)
        num=-num;

    int numSquares=num;
    for(int i=1;i<num;i++)
    {
        numSquares=numSquares+num;
    }
    return numSquares;
}

// Optimized using Bitwise operator
// TC O(logN) SC O(1)
int calculateSquare(int num)
{
    // Making the number +ve if it's -ve
    if(num<0)
        num=-num;

    // Base case
    if(num==0)
        return 0;

    // Get floor(num/2) using right shift
    int f = num>>1;
    // If n is odd
    if(num&1==1)
    {
        return ((calculateSquare(f)<<2)+(f<<2)+1);
    }
    // If n is even
    else
    {
        return (calculateSquare(f)<<2);
    }
}