int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int startColor = image[sr][sc];

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        image[sr][sc] = color;
        visited[sr][sc] = true;
        q.push({sr, sc});

        while (q.size() > 0) {
            auto [x, y] = q.front(); q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dr[i];
                int ny = y + dc[i];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n ) continue;
                if (visited[nx][ny] || image[nx][ny] != startColor) continue;

                visited[nx][ny] = true;
                q.push({nx, ny});
                image[nx][ny] = color;
            }
        }

        return image;
    }
};