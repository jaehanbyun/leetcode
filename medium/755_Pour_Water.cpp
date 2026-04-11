class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        for (int i=0; i<volume; ++i) {
            int pos = getFirstLowerFromLeft(heights, k);
            if (pos == k) {
                pos = getFirstLowerFromRight(heights, k);
            }
            heights[pos]++;
        }

        return heights;
    }

    int getFirstLowerFromLeft(vector<int>& heights, int k) {
        int i = k;
        int minIndex = k;
        int minSoFar = heights[k];
        while (i >= 0) {
            if (heights[i] < minSoFar) {
                minIndex = i;
                minSoFar = heights[i];
            } else if (i < k && heights[i+1] < heights[i]) {
                break;
            }
            i--;
        }

        return minIndex;
    }

    int getFirstLowerFromRight(vector<int>& heights, int k) {
        int i = k;
        int minIndex = k;
        int minSoFar = heights[k];
        while (i < heights.size()) {
            if (minSoFar > heights[i]) {
                minIndex = i;
                minSoFar = heights[i];
            } else if (k < i && heights[i-1] < heights[i]) {
                break;
            }
            i++;
        }
        return minIndex;
    }
};