class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {};
        int cols[9][9] = {};
        int boxes[9][9] = {};

        for (int r=0; r<9; ++r) {
            for (int c=0; c<9; ++c) {
                if (board[r][c] == '.') continue;
                int d = board[r][c] - '1';
                int b = (r/3) * 3 + (c/3);
                if (rows[r][d] || cols[c][d] || boxes[b][d]) return false;
                rows[r][d] = cols[c][d] = boxes[b][d] = 1;
            }   
        }
        
        return true;
    }
};