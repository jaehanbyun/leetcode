class Solution {
public:
    string largestGoodInteger(string num) {
        char best = '\0';

        for (int i = 0; i < (int)num.size(); i++) {
            if (num[i] == num[i+1] and num[i] == num[i+2]) {
                if (num[i] > best) best = num[i];
            }
        }

        return (best == 0) ? string() : string(3, best);
    }
};