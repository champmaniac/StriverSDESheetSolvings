// Brute force  TC O(N*M+max(N,M))

void setMatrixOnes(vector<vector<int>> &mat, int n, int m) 
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



// Optimized TC O(N*M) SC O(N+M)
void setMatrixOnes(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here.
    int row =n, col=m;
    vector<int> rowNumber (row,false);
    vector<int> colNumber(col,false);
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]==1){
                rowNumber[i]=true;
                colNumber[j]=true;
            }
        }
    }
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(rowNumber[i]==true || colNumber[j]==true)
                mat[i][j]=1;
        }
    }
}

