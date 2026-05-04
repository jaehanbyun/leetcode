class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 1. find the transpose of the matrix
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }

        // 2. reverse the rows of the matrix
        for (int i=0; i<n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};