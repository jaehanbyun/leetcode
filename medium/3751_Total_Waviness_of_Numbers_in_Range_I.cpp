class Solution {
public:
    vector<int> toDigits(int num) {
        vector<int> digits;
        string s = to_string(num);

        for (char c: s) {
            digits.push_back(c - '0');
        }
        return digits;
    }

    int countWaviness(int num) {
        if (num < 100) return 0;

        vector<int> d = toDigits(num);
        int n = d.size();
        int cnt = 0;

        for (int i=1; i+1<n; ++i) {
            if ((d[i] > d[i-1] && d[i] > d[i+1]) ||
                (d[i] < d[i-1] && d[i] < d[i+1])) {
                cnt++;
            }
        }

        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int i=num1; i<=num2; ++i) {
            ans += countWaviness(i);
        }

        return ans;
    }
};