/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

// Greedy Approach

/*You are required to complete this method*/
bool comp(struct val p1, struct val p2){
    return p1.second<p2.second;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
    sort(p,p+n,comp);
    int i=0,j=1;
    int cnt=1;
    while(j<n){
        if(p[i].second<p[j].first) {
            cnt++;
            i=j;
            j++;
        }
        else j++;
    }
    return cnt;
}