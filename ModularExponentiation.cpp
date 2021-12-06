// Brute Force
// TC O(N) SC O(1)
int modularExponentiation(int x, int n, int m) {
	int ans=1;
	for(int i=1;i<=n;i++){
		ans = (1LL* ans*x)%m;
	}
	return ans;
}

// Recursive Approach
// TC O(logN) SC O(logN)
int modularExponentiation(int x, int n, int m) {
	// Base case
	if(n==0)
		return 1;
	int ans = modularExponentiation(x,n/2,m);
	if(n%2==0)
		return (1ll*ans*ans)%m;
	else
		return (1ll*(1ll*ans*ans)%m*x%m)%m;
}