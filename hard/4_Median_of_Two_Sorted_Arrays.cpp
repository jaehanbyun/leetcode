class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        int half = (m + n + 1) / 2;

        int l = -1; 
        int r = m;

        while (l + 1 < r) {
            int i = l + (r - l) / 2;
            int j = half - i;

            int aRight = (i == m) ? INT_MAX : nums1[i];
            int bLeft = (j == 0) ? INT_MIN : nums2[j - 1];

            if (bLeft <= aRight) {
                r = i;
            } else {
                l = i;
            }
        }

        int i = r;
        int j = half - i;

        int aLeft = (i == 0) ? INT_MIN : nums1[i-1];
        int aRight = (i == m) ? INT_MAX : nums1[i];

        int bLeft = (j == 0) ? INT_MIN : nums2[j-1];
        int bRight = (j == n) ? INT_MAX : nums2[j];

        int leftMax = max(aLeft, bLeft);

        if ((m+n) % 2 == 1) {
            return leftMax;
        }

        int rightMin = min(aRight, bRight);
        
        return (double)(leftMax + rightMin) / 2.0;
    }
};