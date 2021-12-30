// Brute Force
// TC O(N^2) SC O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int curProd=1;
            for(int j=i;j<n;j++){
                curProd*=nums[j];
                ans=max(ans,curProd);
            }
        }
        return ans;
    }
};

// Optimized using Dp (Tabulation)
// TC O(N) SC O(N)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> dpMin(nums),dpMax(nums);
        int ans =nums[0];
        for(int i=1;i<n;i++){
            dpMin[i]=min(nums[i],nums[i]*(nums[i]>=0?dpMin[i-1]:dpMax[i-1]));
            dpMax[i]=max(nums[i],nums[i]*(nums[i]>=0?dpMax[i-1]:dpMin[i-1]));
            ans=max(ans,dpMax[i]);
        }
        return ans;
    }
};


// Space-Optimized using Dp (Tabulation)
// TC O(N) SC O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int dpMin =nums[0],dpMax =nums[0];
        int ans =nums[0];
        for(int i=1;i<n;i++){
            auto prevDpMin = dpMin, prevDpMax = dpMax;
            dpMin=min(nums[i],nums[i]*(nums[i]>=0?prevDpMin:prevDpMax));
            dpMax=max(nums[i],nums[i]*(nums[i]>=0?prevDpMax:prevDpMin));
            ans=max(ans,dpMax);
        }
        return ans;
    }
};