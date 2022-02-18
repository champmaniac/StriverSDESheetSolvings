class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> v;
        priority_queue<int> pq;
        for(int i=0;i<K;i++){
            for(int j=0;j<K;j++){
                pq.push(arr[i][j]);
            }
        }
        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};