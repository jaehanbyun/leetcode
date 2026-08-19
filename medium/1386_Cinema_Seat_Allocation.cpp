class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        for (auto& r: reservedSeats) {
            int row = r[0], seat = r[1];
            if (2 <= seat && seat <= 9) {
                rowMask[row] |= (1 << (seat - 2)); // 2 ~ 9 -> 0 ~ 7 bit 표현
            }
        }

        long long ans = 2LL * (n - (long long)rowMask.size());

        long long left = 0b00001111;
        long long mid = 0b00111100;
        long long right = 0b11110000;

        for (auto& [row, mask]: rowMask) {
            int l = (mask & left) == 0;
            int r = (mask & right) == 0;
            
            if (l && r) ans += 2;
            else if (l || r || (mask & mid) == 0) ans++;
        }

        return (int)ans;
    }
};