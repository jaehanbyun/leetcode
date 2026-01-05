class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int negCnt = 0;
        int absMinElement = 1e5;
        long long sum = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (matrix[r][c] < 0) {
                    negCnt++;
                }
                absMinElement = min(absMinElement, abs(matrix[r][c]));
                sum += abs(matrix[r][c]);
            }
        }
        
        if (negCnt % 2 == 1) {
            return sum - (absMinElement * 2);
        }
        return sum;
    }
};