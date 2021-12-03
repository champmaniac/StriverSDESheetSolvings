// Brute force 
// TC O(logN) SC O(1)
#include<bits/stdc++.h>
int findMSB(int n){
	// Write your code here
    // Base case
    if(n==0)
        return 0;
    n=n/2;
    int count =0;
    while(n!=0)
    {
        n=n/2;
        count++;
    }
    return 1<<count;
    
}

// Optmized using Right Shift and Bit-Wise OR
// TC O(1) SC O(1)

int findMSB(int n){
	n=n|n>>1;
	n=n|n>>2;
	n=n|n>>4;
	n=n|n>>8;
	n=n|n>>16;

	n=n+1;
	return (n>>1);

}