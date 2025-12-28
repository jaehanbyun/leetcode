class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;

        int n = grid[0].size();
        int currRowNegativeIndex = n - 1;

        for (auto& row: grid) {
            while (currRowNegativeIndex >=0 && row[currRowNegativeIndex] < 0) {
                currRowNegativeIndex--;
            }

            cnt += (n - (currRowNegativeIndex + 1));
        }

        return cnt;   
    }
};