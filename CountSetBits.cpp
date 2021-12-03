// Brute Force
// TC O(NlogN) SC O(1)
int countSetBitsHelper(int n) {
    int count = 0;
    while (n) {
        // Check if last bit is set
        if(n % 2 != 0){
            count += 1;
        }
        // Divide by 2
        n >>= 1;
    }
    return count;
}
int countSetBits(int n) {
    int mod = (int)1e9 + 7;
    int count = 0;

    for (int i = 1; i <= n; i++) {        
        // For each number find it's contribution to the count
        count = (count + countSetBitsHelper(i)) % mod;
    }
    return count;
}

// Optimized
// TC O(logN) SC O(1)
int countSetBits(int n) {
    int mod = (int)1e9+7;
    n++;
    int powerOf2=2;
    int count=n/2;
    while(powerOf2<=n)
    {
        int totalPairs = n/powerOf2;
        count = (count+((totalPairs/2)*powerOf2)%mod)%mod;
        if(totalPairs&1)
        {
            count=(count+n%powerOf2)%mod;
        }
        // Next power of 2
        powerOf2<<=1;

    }
    count%=mod;
    return count;
}