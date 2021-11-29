// Brute Force Using another array
// TC O(N*2360) SC O(1)
int calculateMinPatforms(int arr[], int dep[], int n) {
    int platformsNeeded[2360]={0};
    int minNumberOfPlat = 1;
    for(int i=0;i<n;i++){
        for(int j=arr[i];j<dep[i];j++){
            platformsNeeded[j]++;
            minNumberOfPlat=max(minNumberOfPlat,platformsNeeded[j]);
        }
        
    }
    return minNumberOfPlat;
}
// Optimized using sorting
// TC O(NlogN) SC O(1)

#include<bits/stdc++.h>
int calculateMinPatforms(int arr[], int dep[], int n) {
    // Write your code here.
    sort(arr,arr+n);
    sort(dep,dep+n);
    int plat_needed=1, res=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j])
        {
            plat_needed++;
            i++;
        }
        else if(arr[i]>dep[j])
        {
            plat_needed--;
            j++;
        }
        if(plat_needed>res)
            res=plat_needed;
    }
    return res;
}

// Most Optimized using cumulative sum
// TC O(N) SC O(1)
int calculateMinPatforms(int arr[], int dep[], int n) {
    int platformsNeeded[2361]={0};
    int minNumberOfPlat=1;

    for(int i=0;i<n;i++)
    {
        ++platformsNeeded[arr[i]];
        --platformsNeeded[dep[i]+1];
    }

    for(int i=0;i<2361;i++){
        platformsNeeded[i]=platformsNeeded[i]+platformsNeeded[i-1];
        minNumberOfPlat=max(minNumberOfPlat,platformsNeeded[i]);
    }
    return minNumberOfPlat;
}