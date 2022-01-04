class solution{
private:
	void PrintF(int ind,vector<int> &ds, int arr[], int n){
		if(ind==n) {
			for(auto it: ds){
				cout<<it<<"";
			}
			cout<<endl;
			return;
		}

		// not pick or not take condition, this element is not added in the subsequence
		PrintF(ind+1,ds,arr,n);
		//take or pick the particular index in the subsequence
		ds.push_back(arr[ind]);
		PrintF(ind+1,ds,arr,n);
		ds.pop_back();
	}
public:
	vector<int> recursion(){
		int n = 3;
		int arr[]= {3,1,2};
		vector<int> ds;
		PrintF(0,ds,arr,n);
		return ds;
	}
};


