class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxVal = 0;
        int n = height.size();
        int l = 0, r = n - 1;

        while (l < r) {
            int h = min(height[l], height[r]);
            int w = r - l;
            int s = h * w;
            maxVal = max(maxVal, s);

            if (height[l] < height[r]) {
                ++l;
            }
            else {
                --r;
            }
        }

        return maxVal;
    }
};