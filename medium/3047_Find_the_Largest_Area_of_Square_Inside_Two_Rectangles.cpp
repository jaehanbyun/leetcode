class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long best = 0;

        for (int i = 0; i < n; ++i) {
            long long aLX = bottomLeft[i][0], aLY = bottomLeft[i][1];
            long long aRX = topRight[i][0],   aRY = topRight[i][1];

            for (int j = i + 1; j < n; ++j) {
                long long bLX = bottomLeft[j][0], bLY = bottomLeft[j][1];
                long long bRX = topRight[j][0],   bRY = topRight[j][1];

                long long ix1 = max(aLX, bLX);
                long long iy1 = max(aLY, bLY);
                long long ix2 = min(aRX, bRX);
                long long iy2 = min(aRY, bRY);

                if (ix1 < ix2 && iy1 < iy2) {
                    long long w = ix2 - ix1;
                    long long h = iy2 - iy1;
                    long long side = min(w, h);
                    best = max(best, side * side);
                }
            }
        }
        return best;
    }
};