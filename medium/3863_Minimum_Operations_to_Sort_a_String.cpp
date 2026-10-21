class Solution {
public:
    int minOperations(string s) {
        if (is_sorted(s.begin(), s.end())) return 0;

        int n = s.size();
        if (n == 2) return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0] == mn || s[n-1] == mx) return 1;

        if (s.find(mn) != n-1 || s.rfind(mx) != 0) return 2;

        return 3;
    }
};