class Solution {
public:
    int m, n;
    
    set<pair<int, int>> find(vector<vector<int>>& board) {
        set<pair<int, int>> crushedSet;
        
        for (int r=1; r<m-1; ++r) {
            for (int c=0; c<n; ++c) {
                if (board[r][c] == 0) continue;

                if (board[r][c] == board[r-1][c] && board[r][c] == board[r+1][c]) {
                    crushedSet.insert({r, c});
                    crushedSet.insert({r-1, c});
                    crushedSet.insert({r+1, c});
                }
            }
        }

        for (int r=0; r<m; ++r) {
            for (int c=1; c<n-1; ++c) {
                if (board[r][c] == 0) continue;

                if (board[r][c] == board[r][c-1] && board[r][c] == board[r][c+1]) {
                    crushedSet.insert({r, c});
                    crushedSet.insert({r, c-1});
                    crushedSet.insert({r, c+1});
                }
            }
        }

        return crushedSet;
    }

    void crush(vector<vector<int>>& board, set<pair<int, int>> crushedSet) {
        for (pair<int, int> p: crushedSet) {
            board[p.first][p.second] = 0;
        }
    }

    void drop(vector<vector<int>>& board) {
        for (int c=0; c<n; ++c) {
            int lowestZero = -1;
            for (int r=m-1; r>=0; --r) {
                if (board[r][c] == 0) {
                    lowestZero = max(lowestZero, r);
                } else if (lowestZero >= 0) {
                    int tmp = board[r][c];
                    board[r][c] = 0;
                    board[lowestZero--][c] = tmp;
                }
            }
        } 
    }

    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        set<pair<int, int>> crushedSet;

        crushedSet = find(board);
        while (!crushedSet.empty()) {
            crush(board, crushedSet);
            drop(board);
            crushedSet = find(board);
        }

        return board;
    }
};