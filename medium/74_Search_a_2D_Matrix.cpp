class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        int l = -1;
        int r = m * n;

        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            int x = mid / n;
            int y = mid % n;

            if (matrix[x][y] >= target) r = mid;
            else l = mid;
        }

        if (r < m * n && matrix[r/n][r%n] == target) return true;
        return false;
    }
};
