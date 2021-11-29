// Greedy approach
// TC O(NlogN) SC O(N)
#include<algorithm>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<pair<int,int>> activity(n);
    for(int i=0;i<n;;i++)
    {
        activity[i].first = finish[i];
        activity[i].second=start[i];
    }
    // Sort the meetings according to their Finishing Time.
    sort(activity.begin(),activity.end());

    int maxActivity=1;
    int currentTime=activity[0].first;

    for(int i=1;i<n;i++){
        // Find the next meeting available
        if(activity[i].second>=currentTime){
            maxActivity++;
            currentTime=activity[i].first;
        }
    }
    return maxActivity;
}