// Dutch national flag algo   TC O(N)  SC O(1)

#include<bits/stdc++.h>
void sort012(int *nums, int n)
{
    int lo = 0;
    int hi = n-1;
    int mid=0;
    while(mid<=hi){
        switch(nums[mid]){
            case 0:
            	swap(nums[lo++],nums[mid++]);
            	break;
            case 1:
            	mid++;
            	break;
            case 2:
            	swap(nums[mid],nums[hi--]);
            	break;
        }
    }
}