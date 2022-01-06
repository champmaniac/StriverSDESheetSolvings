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


// Print all subsequences whose sum is the given sum

class solution{
private:
	void PrintS(int ind,vector<int> &ds, int s, int sum, int arr[], int n){
		if(ind==n) {
			if(s==sum){
				for(auto it: ds){
					cout<<it<<"";
				}
				cout<<endl;
			}
			return;
		}
		ds.push_back(arr[ind]);
		s+=arr[ind];
		PrintS(ind+1,ds,s,sum,arr,n);
		s-=arr[ind];
		ds.pop_back();
		PrintS(ind+1,ds,s,sum,arr,n);
	}
public:
	vector<int> recursion(){ 
		int n = 3;
		int arr[]= {1,2,1};
		vector<int> ds;
		PrintS(0,ds,0,sum,arr,n);
		return ds;
	}
};


// Print only one subsequence whose sum is the given sum

class solution{
private:
	bool PrintS(int ind,vector<int> &ds, int s, int sum, int arr[], int n){
		if(ind==n) {
			// condition satisfied
			if(s==sum){
				for(auto it: ds){
					cout<<it<<"";
				}
				cout<<endl;
				return true;
			}
			else return false;
		}
		ds.push_back(arr[ind]);
		s+=arr[ind];
		if(PrintS(ind+1,ds,s,sum,arr,n)==true)
			return true;
		s-=arr[ind];
		ds.pop_back();
		if(PrintS(ind+1,ds,s,sum,arr,n)==true)
			return true;
		return false;
	}
public:
	vector<int> recursion(){ 
		int n = 3;
		int arr[]= {1,2,1};
		vector<int> ds;
		PrintS(0,ds,0,sum,arr,n);
		return ds;
	}
};


// Count the subsequence whose sum is the given sum=k

// TC O(2^N)

class solution{
private:
	int PrintS(int ind,int s, int sum, int arr[], int n){
		// condition not satisfied
		// strictly done if array contains only positives
		if(s>sum) return 0;
		if(ind==n) {
			// condition satisfied
			if(s==sum){
				return 1;
			}
			// condition not satisfied
			else return 0;
		}
		s+=arr[ind];
		int l = PrintS(ind+1,s,sum,arr,n);
		s-=arr[ind];
		int r = PrintS(ind+1,s,sum,arr,n);
		return l+r;
	}
public:
	vector<int> recursion(){ 
		int n = 3;
		int sum=2;
		int arr[]= {1,2,1};
		cout<<PrintS(0,0,sum,arr,n)<<"";
	}
};





