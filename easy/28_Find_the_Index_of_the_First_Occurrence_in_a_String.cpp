class Solution {
public:
    int strStr(string haystack, string needle) {
        int hl = haystack.size();
        int nl = needle.size();

        if (nl == 0) return 0;
        if (hl < nl) return -1;

        for (int i=0; i<=hl-nl; ++i) {
            int j = 0;
            while (j<nl && haystack[i+j] == needle[j]) {
                ++j;
            }
            if (j==nl) return i;
        }

        return -1;
    }
};