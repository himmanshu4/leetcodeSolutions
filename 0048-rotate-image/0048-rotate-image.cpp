class Solution {
public:

    void rotate(vector<vector<int>>& matrix) {
        // i th row, jth column
        // n-1-i column, j th row
        for (int i = 0; i < (0+matrix.size()) ; i++) {
            for (int j = i; j < matrix.size()-i -1; j++) {
                int new_i, new_j, prevValue=matrix[i][j];

                for (int swap_instance = 0; swap_instance < 4;
                     swap_instance++) {
                    new_i = j;
                    new_j = matrix.size() - 1 - i;
                    swap(prevValue,matrix[new_i][new_j]);
                    i=new_i;
                    j=new_j;
                }
            }
        }
    }
};