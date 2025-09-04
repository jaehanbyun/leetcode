class Solution {
public:
    int findClosest(int x, int y, int z) {
        int gapBetweenXandZ = abs(x - z), gapBetweenYandZ = abs(y - z); 
        
        return (gapBetweenXandZ < gapBetweenYandZ) ? 1 : (gapBetweenYandZ < gapBetweenXandZ) ? 2 : 0;
    }
};