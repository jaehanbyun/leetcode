class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int r = words.size();
        for (int i=0; i<r; ++i) {
            string rowString = words[i];
            string colString = "";
            for (int j=0; j<r; ++j) {
                if (i >= words[j].length()) break;
                colString += words[j][i];
            }
            if (rowString != colString) {
                return false;
            }
        }
        return true;
    }
};