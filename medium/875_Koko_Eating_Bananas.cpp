class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto can = [&](long long k) -> bool {
            long long hours = 0;

            for (int pile: piles) {
                hours += (pile + k - 1) / k;
            }

            return hours <= h;
        };

        int l = 0;
        int r = *max_element(piles.begin(), piles.end());

        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            if (can(mid)) r = mid;
            else l = mid;
        }

        return r;
    }
};