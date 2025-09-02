class Solution {
public:
    bool checkIncludePoints(vector<vector<int>>& points, int x1, int y1, int x2, int y2) {
        for (const auto& point : points) {
            int curX = point[0], curY = point[1];

            // A 또는 B이면 스킵
            if ((curX == x1 && curY == y1) || (curX == x2 && curY == y2)) continue;

            // 경계 포함해서 내부에 점이 있으면 실패
            if (x1 <= curX && curX <= x2 && y2 <= curY && curY <= y1) {
                return false;
            }
        }
        return true;
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1]; // A(upper-left)
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int x2 = points[j][0], y2 = points[j][1]; // B(lower-right)
                // 같은 x 또는 같은 y도 허용(문제에서 선분 허용)
                if (x1 <= x2 && y2 <= y1 && checkIncludePoints(points, x1, y1, x2, y2)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};