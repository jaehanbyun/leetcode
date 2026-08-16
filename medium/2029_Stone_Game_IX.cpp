class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3, 0);
        for (int x: stones) {
            int r = x % 3;
            if (r == 0) cnt[0]++;
            else if (r == 1) cnt[1]++;
            else cnt[2]++;
        }
        if (cnt[0] % 2 == 0) {
            return cnt[1] >= 1 && cnt[2] >= 1;
        }
        return cnt[1] - cnt[2] > 2 || cnt[2] - cnt[1] > 2;
    }
};