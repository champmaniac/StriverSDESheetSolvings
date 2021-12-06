// Brute Force
// TC O(N) SC O(1)
int modularExponentiation(int x, int n, int m) {
	int ans=1;
	for(int i=1;i<=n;i++){
		ans = (1LL* ans*x)%m;
	}
	return ans;
}