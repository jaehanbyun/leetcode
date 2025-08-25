class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res(m * n);

        int r = 0, c = 0, dir = +1;
        for (int k = 0; k < m * n; ++k) {
            res[k] = mat[r][c];

            if (dir == +1) { // up diagonal
                if (c == n - 1) {      // 오른쪽 경계
                    ++r; dir = -1;
                } else if (r == 0) {   // 위쪽 경계
                    ++c; dir = -1;
                } else {               // 일반 이동
                    --r; ++c;
                }
            } else { // down diagonal
                if (r == m - 1) {      // 아래 경계
                    ++c; dir = +1;
                } else if (c == 0) {   // 왼쪽 경계
                    ++r; dir = +1;
                } else {               // 일반 이동
                    ++r; --c;
                }
            }
        }
        return res;
    }
};