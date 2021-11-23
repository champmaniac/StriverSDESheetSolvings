// Brute Force TC O(N^2)

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j])
                return arr[i];
            }
    }
    return -1;
}

// Optimized using set TC O(N)
int findDuplicate(vector<int> &arr, int n)
{
	unordered_set<int> st;
	for(auto i:arr)
	{
		if(st.find(i)!=st.end())
		{
			return i;
		}
		else
		{
			st.insert(i);
		}
	}
	return -1;
}