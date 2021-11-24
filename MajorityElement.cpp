// // Brute Force TC O(N^2) SC (1)
// int findMajorityElement(int arr[], int n) {
// 	for(int i=0;i<n;i++){
// 		int maxCount=0;
// 		for(int j=0;j<n;j++){
// 			if(arr[i]==arr[j])
// 				maxCount++;
// 		}
// 		if(maxCount>n/2)
// 		return arr[i];
// 	}
// 	return -1;
// }

// Optimized using Hashmap  TC O(N) SC O(N)
int findMajorityElement(int arr[], int n) {
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		mp[arr[i]]++;
		if(mp[arr[i]]>n/2)
			return arr[i];
	}
	return -1;
}


// Most Optimized  Boyer-Moore majority vote algo  TC O(N) SC O(1)

// int findMajorityElement(int arr[], int n) {
//    int ele = arr[0], count=1;
//    for(int i=1;i<n;i++)
//    {
//    	if(arr[i]==ele)
//    		count++;
//     else
//     	count--;
//     if(count==0)
//    	{
//    		ele = arr[i];
//    		count=1;
//    	}
//    }

//    	count =0;
//    	for(int i=0;i<n;i++){
//    		if(arr[i]==ele)
//    		{
//    			count++;
//    		}
//    	}
   		
//    	if(count>n/2)
//    		return ele;
//    	return -1;
// }

