class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAlt = 0;
        int highAlt = currAlt;

        for (int altitudeGain: gain) {
            currAlt += altitudeGain;
            highAlt = max(highAlt, currAlt);
        }

        return highAlt;
    }
};