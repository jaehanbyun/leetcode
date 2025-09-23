class Solution {
public:
    int compareVersion(string a, string b) {
        size_t i = 0, j = 0;
        size_t n = a.size(), m = b.size();
        
        while (i < n || j < m) {
            long long x = 0;
            while (i < n && a[i] != '.') {
                x = x * 10 + (a[i] - '0');  
                ++i;
            }
        
            long long y = 0;
            while (j < m && b[j] != '.') {
                y = y * 10 + (b[j] - '0');
                ++j;
            }

            if (x < y) return -1;
            if (x > y) return 1;

            if (i < n && a[i] == '.') ++i;
            if (j < m && b[j] == '.') ++j;
        }
        return 0;
    }
};