// Brute Force
// TC O(M+N*Log(M+N)) SC O(1)
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    for(int i=0;i<n;i++){
        arr1[i+m]= arr2[i];
    }
    sort(arr1.begin(),arr1.end());
    return arr1;
}

// Optimized Greedy Approach
// TC O(M+N) SC O(1)
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i =m-1;
	int j =n-1;
	int lastIndex = m+n-1;
	while(j>=0){
		if(i>=0 && arr1[i]>arr2[j]){
			arr1[lastIndex] =arr1[i];
			i--;
		}
		else{
			arr1[lastIndex]=arr2[j];
			j--;
		}
		lastIndex--;
	}
	return arr1;
}