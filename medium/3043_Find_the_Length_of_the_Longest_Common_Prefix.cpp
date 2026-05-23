class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> arr1Prefixes;

        for (int num: arr1) {
            while (!arr1Prefixes.count(num) && num > 0) {
                arr1Prefixes.insert(num);
                num /= 10;
            }
        }

        int longestPrifix = 0;

        for (int num: arr2) {
            while (!arr1Prefixes.contains(num) && num > 0) {
                num /= 10;
            }
            if (num > 0) {
                longestPrifix = max(longestPrifix, (int)log10(num) + 1);
            }
        }

        return longestPrifix;
    }
};