// Brute Force TC O(N^N) SC(1)
int ZeroPairSum(int n, vector<int> arr){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==0)
                count++;
        }
    }
    if(count>0)
        return count;
    return 0;
}

// Optimized TC 