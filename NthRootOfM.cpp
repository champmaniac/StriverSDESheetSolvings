// Binary search approach
// TC O(log(m)*log(n)) SC O(1)
#include <bits/stdc++.h>
double multiply(double m,int n)
{
	double ans=1.0;
	for(int i=1;i<=n;i++){
		ans=ans*m;
	}
	return ans;
}
double findNthRootOfM(int n, long long m) {
	// Write your code here.
	double low=1;
	double high=m;
	double eps=1e-6;

	while((high-low)>eps)
	{
		double mid = (low+high)/2.0;
		if(multiply(mid,n)<m){
			low=mid;
		}
		else
		{
			high=mid;
		}
	}
	return pow(m,(double)(1.0/(double)n));
}
