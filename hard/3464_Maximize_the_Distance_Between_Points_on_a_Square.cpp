class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        long long S = side;                 
        long long perimeter = 4LL * S;     
        
        vector<long long> arr;
        arr.reserve(n);
        for (auto& p : points) {
            long long x = p[0], y = p[1];
            long long d;
            if (x == 0)            d = y;                    // 왼쪽
            else if (y == S)       d = S + x;                // 위
            else if (x == S)       d = 3LL * S - y;          // 오른쪽
            else /* y == 0 */      d = 4LL * S - x;          // 아래
            arr.push_back(d);
        }
        sort(arr.begin(), arr.end());
        
        auto canPick = [&](int start, long long limit) {
            long long last = arr[start];
            int idx = start;
            int count = 1;
            while (count < k) {
                auto it = lower_bound(arr.begin() + idx + 1, arr.end(), last + limit);
                if (it == arr.end()) return false;
                idx = (int)(it - arr.begin());
                last = arr[idx];
                if (last - arr[start] > perimeter - limit) return false;
                count++;
            }
            return true;
        };
        
        auto feasible = [&](long long limit) {
            for (int s = 0; s < n; ++s) {
                if (canPick(s, limit)) return true;
            }
            return false;
        };
        
        long long lo = 1, hi = S;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (feasible(mid)) lo = mid;
            else               hi = mid - 1;
        }
        return (int)lo;
    }
};