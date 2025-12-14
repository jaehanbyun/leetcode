class Solution {
public:
    int numberOfWays(string corridor) {
        const long long mod= 1'000'000'007LL;

        int l = corridor.size();
        vector<int> seats;
        seats.reserve(l);

        for (int i = 0; i < l; ++i) {
            if (corridor[i] == 'S') seats.push_back(i);
        }

        int m = seats.size();
        if (m % 2 == 1 || m < 2) return 0;
        if (m == 2) return 1; 

        long long ans = 1;
        for (int i = 1; i < m - 1; i+=2) {
            ans = (ans * (seats[i+1] - seats[i])) % mod; 
        }

        return ans;
    }
};