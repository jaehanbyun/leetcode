class Solution {
public:
    static double getTriArea(const vector<int>& A, const vector<int>& B, const vector<int>& C) {
        int x1 = B[0] - A[0], y1 = B[1] - A[1];
        int x2 = C[0] - A[0], y2 = C[1] - A[1];
        int cross = x1 * y2 - y1 * x2; 
        return fabs(0.5 * (double)cross);
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0.0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    ans = max(ans, getTriArea(points[i], points[j], points[k]));
                }
            }
        }
        return ans;
    }
};