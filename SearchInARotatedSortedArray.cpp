// Optimzed way using Binary Search
// TC O(logN) SC O(1)

int search(int*arr,int n,int key)
{
	int start =0,end=n-1;
	while(start<=end)
	{
		int mid = (start+end)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]>=arr[start]){
			if(arr[start]<=key && key<=arr[mid])
				end=end-1;
			else
				start=mid+1;
		}
		else
		{
			if(arr[key]>=key && key>=arr[mid])
				start=mid+1;
			else
				end=mid-1;
		}
	}
	return -1;
}