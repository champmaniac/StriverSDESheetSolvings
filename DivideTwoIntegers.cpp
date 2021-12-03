// Brute force using substraction method
// TC O(N/M) SC O(1)
int divideTwoInteger(int dividend, int divisor) {
	// Write your code here.
    int sign = ((dividend<0)^(divisor<0))? -1:1;

    divisor=abs(divisor);
    dividend=abs(dividend);

    int quotient=0;
    while(dividend>=divisor)
    {
    	dividend-=divisor;
    	++quotient;
    }

    return quotient*sign;
} 

// Optmized using Bit masking
// TC O(1) SC O(1)
int divideTwoInteger(long long dividend, long long divisor) {
	// Write your code here.
    int sign = ((dividend<0)^(divisor<0))? -1:1;

    divisor=abs(divisor);
    dividend=abs(dividend);

    long long quotient=0,temp=0;
    for(int i=31;i>=0;i--)
    {
        if(temp+(divisor<<i)<=dividend){
        	temp+=divisor<<i;
        	quotient|=1<<i;
        }
    }

    if(sign==-1) quotient=-quotient;
    return quotient;
} 