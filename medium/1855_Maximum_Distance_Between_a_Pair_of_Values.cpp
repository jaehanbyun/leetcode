class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int np1 = 0, np2 = 0;

        while (np1 < nums1.size() && np2 < nums2.size()) {
            if (nums1[np1] > nums2[np2]) {
                np1++;
            }
            else {
                ans = max(ans, np2 - np1);
                np2++;
            }
        }

        return ans;
    }
};
