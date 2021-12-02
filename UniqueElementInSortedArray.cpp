// Brute Force using hashing
// TC O(N) SC O(N)


#include <unordered_map>
int uniqueElement(vector<int> arr, int n){
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		mp[arr[i]]++;
	}

	for(auto m:mp){
		if(m.second==1)
			return m.first;
	}
}

// Space Optimzed using Bit Manipulation
// TC O(N) SC O(1)

int uniqueElement(vector<int> arr, int n){
	int ans =0;
	for(auto element:arr)
	{
		ans^=element;
	}
	return ans;
}


// Optimzed using Binary Search
// TC O(logN) SC O(1)

int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
	int low = 0, high = arr.size()-2;
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(arr[mid]==arr[mid^1]){
			low =mid+1;
		}
		else{
			high = mid-1;
		}
	}
	return arr[low];
}
