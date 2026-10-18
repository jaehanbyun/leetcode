class Solution {
    int m, n;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    vector<vector<bool>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != word[0]) continue;
                visited[i][j] = true;
                if (dfs(i, j, 0, board, word)) return true;
                visited[i][j] = false;
            }
        return false;
    }

private:
    bool inRange(int r, int c) {
        return 0 <= r && r < m && 0 <= c && c < n;
    }
    
    bool dfs(int r, int c, int idx, vector<vector<char>>& board, string target) {
        if (idx == target.size() - 1) return true;

         for (int i = 0; i < 4; ++i) {
            int nx = r + dr[i], ny = c + dc[i];

            if (!inRange(nx, ny) || visited[nx][ny] || board[nx][ny] != target[idx + 1]) continue;

            visited[nx][ny] = true;
            if (dfs(nx, ny, idx + 1, board, target)) return true;
            visited[nx][ny] = false;
        }
        
        return false;
    }
};