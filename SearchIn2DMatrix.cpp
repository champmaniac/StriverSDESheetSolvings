// Brute Force O(N*M)
bool findTargetInMatrix(vector<vector<int>>&mat,int m,int n,int target) {
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j]==target)
				return true;
		}
	}
	return false;
}
// Optimized Binary Search TC O(log(N*M))
#include<vector>
bool findTargetInMatrix(vector<vector<int>>&mat,int m,int n,int target) {
	int row_pointer=0, col_pointer=n-1;
	int flag=0;
	while(row_pointer<m && col_pointer>=0){
		if(mat[row_pointer][col_pointer]==target){
			flag=1;
			break;
		}
		else if(mat[row_pointer][col_pointer]>target)
			col_pointer--;
		else
			row_pointer++;
	}
	return flag;
}

