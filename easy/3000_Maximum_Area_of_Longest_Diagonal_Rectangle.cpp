class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        float maxDiagonal = 0;
        int maxArea = 0;
        
        for (auto d: dimensions) {
            float curDiagonal = sqrt(d[0]*d[0] + d[1]*d[1]);
            int area = d[0] * d[1];

            if (curDiagonal > maxDiagonal || (curDiagonal == maxDiagonal && area > maxArea)) {
                maxDiagonal = curDiagonal;
                maxArea = area;
            }
        }

        return maxArea;
    }
};