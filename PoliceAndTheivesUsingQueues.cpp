class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        queue<int> police;
        queue<int> theif;
        
        for(int i=0;i<n;i++){
            if(arr[i]=='P')
                police.push(i);
            else
                theif.push(i);
        }
        
        int ans=0;
        while(!police.empty() && !theif.empty()){
            int policeTop =  police.front();
            int theifTop = theif.front();
            if(abs(policeTop-theifTop)<=k){
                ans++;
                police.pop();
                theif.pop();
            }
            else if(policeTop<theifTop)
                police.pop();
            else
                theif.pop();
        }
        return ans;
    }
};