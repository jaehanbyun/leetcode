class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        
        // p(i)를 i칸에 고이는 물의 양이라고 하면
        // p(i) = min(i의 왼쪽 최고 높이, i의 오른쪽 최고 높이) - height[i]
        while (left <= right) {
            if (leftMax <= rightMax) {
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                right--;
            }
        }

        return water;
    }
};