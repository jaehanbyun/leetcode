class Solution {
    int maxConsecutive(vector<int>& array) {
        sort(array.begin(), array.end());
        int best = 1, cur = 1;
        for (int i = 1; i < array.size(); ++i) {
            if (array[i] == array[i-1] + 1) cur++;
            else {
                best = max(best, cur); 
                cur = 1;
            }
        }
        best = max(best, cur);
        return best;
    } 

public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int bestH = maxConsecutive(hBars);
        int bestV = maxConsecutive(vBars);

        int side = min(bestH + 1, bestV + 1);

        return side * side;
    }
};