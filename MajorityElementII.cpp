// // Brute Force O(N^2)
// vector<int> majorityElementII(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int> ans;
//     for(int i=0;i<n;i++)
//     {
//         int maxCount=1;
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[i]==arr[j])
//                 maxCount++;
//         }
//         if(maxCount>(n/3))
//             ans.push_back(arr[i]);
//     }
//     return ans;

// }

// Optimized using hashmap  TC O(N)  SC O(N)

// #include <unordered_map>
// vector<int> majorityElementII(vector<int> &arr)
// {
//     int n = arr.size();
//     unordered_map<int,int> mp;
//     vector<int> ans;
//     for(int i=0;i<n;i++)
//     {
//         mp[arr[i]]++;
//     }
//     for(auto x:mp)
//     {
//         if(x.second>(n/3))
//             ans.push_back(x.first);
//     }
//     return ans;
// }

// Best Optimized sol TC O(N) SC O(1)

vector<int> majorityElementII(vector<int> &nums)
{
    int n = nums.size();
    int num1=-1,num2=-1,count1=0,count2=0,i;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==num1)
            count1++;
        else if(nums[i]==num2)
            count2++;
        else if(count1==0)
        {
            num1=nums[i];
            count1=1;
        }
        else if(count2==0)
        {
            num2=nums[i];
            count2=1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    vector<int> ans;
    count1=count2=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==num1)
            count1++;
        else if(nums[i]==num2)
            count2++;
    }
    if(count1>n/3)
        ans.push_back(num1);
    if(count2>n/3)
        ans.push_back(num2);

    return ans;
}