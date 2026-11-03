class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        int n = picture[0].size();
        
        unordered_map<int, int> row;
        unordered_map<int, int> col;
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (picture[i][j] == 'B') {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int ans = 0;
        for (int i=0; i<m; ++i) {
            if (row[i] != 1) continue;
            for (int j=0; j<n; ++j) {
                if (picture[i][j] == 'B') {
                    if (col[j] == 1) ans++;
                    break;
                }
            }
        }

        return ans;
    }
};