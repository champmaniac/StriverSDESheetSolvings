// Brute Force TC O(log N) SC (log N)
bool isPowerOfTwo(int n){
	// Base case : '1' is the only element which is a power of 2 i.e 2^0 = 1
	if(n==1)
		return true;
	// All other odd numbers are not power of 2
	else if(n%2!=0 || n==0)
		return false;
	return isPowerOfTwo(n/2);
}

// Optimized code using Bit Manipulation TC O(1) SC O(1)
bool isPowerOfTwo(int n){
	if(n<=0)
		return false;
	if((n&n-1)==0)
		return true;
	return false;
}