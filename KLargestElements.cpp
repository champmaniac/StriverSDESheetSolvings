class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> res;
        while(!pq.empty()){
            int top = pq.top();
            res.push_back(top);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};