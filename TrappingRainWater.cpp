//
// TC O(N) SC O(1)
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long low=0;
    long hi = n-1;
    long res=0,maxleft=0,maxright=0;
    while(low<=hi)
    {
        if(height[low]<=height[hi])
        {
            if(height[low]>=maxleft)
                maxleft=height[low];
            else
                res+=maxleft-height[low];
            low++;
        }
        else
        {
            if(height[hi]>=maxright)
                maxright=height[hi];
            else
                res+=maxright-height[hi];
            hi--;
        }
    }
    return res;
}