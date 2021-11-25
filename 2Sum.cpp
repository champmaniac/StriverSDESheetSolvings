// Brute Force TC O(N^N) SC(1)
int ZeroPairSum(int n, vector<int> arr){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==0)
                count++;
        }
    }
    if(count>0)
        return count;
    return 0;
}

// Optimized hashmap TC O(N) SC O(N)
#include<unordered_map>
int ZeroPairSum(int n, vector<int> arr){
    int count =0;
    // hashmap to store frequency
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }

    // iterating the hashmap
    for(auto it= mp.begin();it!=mp.end();it++)
    {
        int curKey = it->first;
        // checking if curKey is not equal to 0
        // Also checking if -curkey exist in the hashmap or not
        if(curKey!=0 && mp.find(-curKey)!=mp.end())
        {
            count+=(mp[curKey]*mp[-curKey]);
        }
    }

    // border cases when array element is equal to 0
    if(mp.find(0)!=mp.end())
    {
        int f =mp[0];
        count+=(f*(f-1));
    }
    return count/2;

}