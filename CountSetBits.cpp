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