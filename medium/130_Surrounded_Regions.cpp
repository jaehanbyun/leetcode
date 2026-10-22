class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        auto inRange = [&](int r, int c) -> bool {
            return 0 <= r && r < m && 0 <= c && c < n;
        };

        auto bfs = [&](int r, int c) {
            int dr[4] = {-1, 1, 0, 0};
            int dc[4] = {0, 0, -1, 1};
            queue<pair<int, int>> q;
            q.push({r, c});
            board[r][c] = '#';

            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();

                for (int i=0; i<4; ++i) {
                    int nx = x + dr[i], ny = y + dc[i];

                    if (!inRange(nx, ny) || board[nx][ny] != 'O') continue;

                    q.push({nx, ny});
                    board[nx][ny] = '#';
                }
            }
        };

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == 'O' && (i == 0 || i == m-1 || j == 0 || j == n-1)) {
                    bfs(i, j);
                }
            }
        }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
        }
    }
};