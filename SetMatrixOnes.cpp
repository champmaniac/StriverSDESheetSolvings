void setMatrixOnes(vector<vector<int>> &mat, int n, int m) // Brute force
{
    // Write your code here.
    int row =n, col=m;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]==1){
                // setting rows elements -1
                for(int k=0;k<col;k++){
                    if(mat[i][k]==0)
                        mat[i][k]=-1;
                }
                // setting cols elements -1
                for(int k=0;k<row;k++){
                    if(mat[k][j]==0)
                        mat[k][j]=-1;
                }
            }
        }
    }
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]==-1)
                mat[i][j]=1;
        }
    }
}
