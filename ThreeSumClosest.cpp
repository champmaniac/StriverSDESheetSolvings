class Solution{
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int i,j,k,sum;
        int n =arr.size(), closestSum=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++){
            j=i+1,k=n-1;
            while(j<k){
                sum=arr[i]+arr[j]+arr[k];
                if(sum==target) return sum;
                if(abs(target-sum)<abs(target-closestSum))
                    closestSum=sum;
                if(abs(target-sum)==abs(target-closestSum))
                    closestSum=max(closestSum,sum);
                if(sum<target)j++;
                else k--;
            }
        }
        return closestSum;
    }
};