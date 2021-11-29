// Greedy approach
// TC O(NlogN) SC O(1)
#include<algorithm>
bool comparator(pair<int,int>&a, pair<int,int>&b){
    double r1 = (double)a.second/a.first;
    double r2 = (double)b.second/b.first;

    return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    sort(items.begin(),items.end(),comparator);
    double maximumValue=0;
    int currentWeight =0;
    for(int i=0;i<n;i++)
    {
        if(curWeight+items[i].first<=w)
        {
            currentWeight+=items[i].first;
            maximumValue+=items[i].second;
        }
        else
        {
            int remainingWeight = w- currentWeight;
            // picking a fraction pf current item
            maximumValue+=items[i].second*((double) remainingWeight/items[i].first);
            break;
        }
    }
    return maximumValue;
}