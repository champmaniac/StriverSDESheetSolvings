class Solution{
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
        // Your code goes here
        int n = arr1.size(), m = arr2.size();
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            res.push_back(arr1[i]);
        }
        for(int i=0;i<m;i++){
            res.push_back(arr2[i]);
        }
        sort(res.begin(),res.end());
        int size = res.size();
        if(size%2!=0)
            return res[size/2];
        else
        {
            return (res[size/2]+res[size/2-1])/2.00000;
        }
    }
};