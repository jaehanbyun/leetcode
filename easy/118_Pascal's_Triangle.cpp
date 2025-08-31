class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri;
        tri.reserve(numRows);

        for (int i = 0; i < numRows; ++i) {
            tri.emplace_back(i + 1, 1);           // [1, ..., 1]
            for (int j = 1; j < i; ++j) {         // 양 끝 제외
                tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
            }
        }
        return tri;
    }
};