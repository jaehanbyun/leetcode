class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = minutes / 60.0 * 360;
        double hourAngle = (hour % 12) * 30;
        hourAngle += minutes / 60.0 * 30;
        double diff = abs(hourAngle - minAngle);

        return min(diff, 360 - diff);
    }
};