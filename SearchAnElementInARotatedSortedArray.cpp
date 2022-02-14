int Search(vector<int> vec, int K) {
    //code here
    int n =vec.size();
    int start=0,end=n-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(vec[mid]==K)
            return mid;
        else if(vec[mid]>vec[start]){
            if(K>=vec[start] && K<vec[mid]) end=mid-1;
            else start=mid+1;
        }
        else
        {
            if(K<=vec[end] && K>vec[mid]) start=mid+1;
            else end=mid-1;
        }
    }
    return -1;
}