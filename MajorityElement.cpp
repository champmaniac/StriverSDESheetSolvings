int findMajorityElement(int arr[], int n) {
   int ele = arr[0], count=1;
   for(int i=1;i<n;i++)
   {
   	if(arr[i]==ele)
   		count++;
    else
    	count--;
    if(count==0)
   	{
   		ele = arr[i];
   		count=1;
   	}
   }

   	count =0;
   	for(int i=0;i<n;i++){
   		if(arr[i]==ele)
   		{
   			count++;
   		}
   	}
   		
   	if(count>n/2)
   		return ele;
   	return -1;
}

