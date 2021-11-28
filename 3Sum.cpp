// // Brute force
// // TC O(N^3) SC O(1)
#include<set>
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    set<vector<int>> visited;
	vector<vector<int>> res;
    for(int i=0;i<n-2;i++)
    {
    	for(int j=i+1;j<n-1;j++)
    	{
    		for(int m =j+1;m<n;m++)
    		{
    			if(arr[i]+arr[j]+arr[m]==K){
                    vector<int> triplets;
    				triplets.push_back(arr[i]);
                    triplets.push_back(arr[j]);
                    triplets.push_back(arr[m]);
                    sort(triplets.begin(),triplets.end());
                    if(visited.find(triplets)==visited.end())
                    {
                        res.push_back(triplets);
                        visited.insert(triplets);
                    }
    			}
    		}
    	}
    }
   return res;
}

// Optimized Two Pointers
// TC O(N^2) SC O(1)
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>> ans;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++)
	{
		int target = K-arr[i];
		int front = i+1;
		int back =n-1;
		while(front<back)
		{
			int sum = arr[front]+arr[back];
			if(sum<target)
				front++;
			else if(sum>target)
				back--;
			else
			{
				int x = arr[front];
				int y = arr[back];
				ans.push_back({arr[i],arr[front],arr[back]});
				// increamenting front ponter until we reach a diff number
				while(front<back && arr[front]==x){
					front++;
				}
				// decreamenting back pointer until we reach a diff number
				while(front<back && arr[back]==y){
					back--;
				}
			}
		}

		// Ensuring that we don't encounter duplicate values fro arr[i]
		while(i+1<n && arr[i]==arr[i+1])
			i++;
	}
	return ans;
}
