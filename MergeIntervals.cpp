// Brute Force TC O(N^2)
#include<algorithm>
pair<int,int> missingAndRepeating(vector<int> &arr, int n){
	int r,m;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]==arr[j])
			{
				r=arr[i];
				break;
			}
		}
	}

	// calculating the sum of the array
	int currSum=0;
	for(int i=0;i<n;i++){
		currSum+=arr[i];
	}

	// sum of the numbers from 1 to n
	int actualSum=n*(n+1)/2;
	m=actualSum-(currSum-r);
	pair<int,int> ans;
	ans.first=m;
	ans.second=r;

	return ans;
}

// Little Optimized TC O(N*Log(N))
#include<algorithm>
pair<int,int> missingAndRepeating(vector<int> &arr, int n){
	sort(arr.begin(),arr.end());
	int r,m;
	for(int i=0;i<n-1;i++){
		if(arr[i]==arr[i+1])
		{
			r=arr[i];
			break;
		}
	}

	// calculating the sum of the array
	int currSum=0;
	for(int i=0;i<n;i++){
		currSum+=arr[i];
	}

	// sum of the numbers from 1 to n
	int actualSum=n*(n+1)/2;
	m=actualSum-(currSum-r);
	pair<int,int> ans;
	ans.first=m;
	ans.second=r;

	return ans;
}