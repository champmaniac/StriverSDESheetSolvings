// Transpose and reverse TC O(N)

class Solution { 
public:
    
    void transpose(vector<vector<int>> &matrix){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        for(auto &row:matrix){
            reverse(row.begin(),row.end());
        }
    }
};