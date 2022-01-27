class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int normalSubarraySum(int arr[], int n){
        int curSum =arr[0], maxSum=arr[0];
        for(int i=1;i<n;i++){
            curSum = max(curSum+arr[i],arr[i]);
            maxSum = max(curSum,maxSum);
        }
        return maxSum;
    }
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int normalMaxSum = normalSubarraySum(arr,num);
        if(normalMaxSum<0) return normalMaxSum;
        
        int arrSum=0;
        for(int i=0;i<num;i++){
            arrSum+=arr[i];
            arr[i]=-arr[i];
        }
        
        int circularMaxSum = arrSum+normalSubarraySum(arr,num);
        return max(normalMaxSum,circularMaxSum);
    }
};