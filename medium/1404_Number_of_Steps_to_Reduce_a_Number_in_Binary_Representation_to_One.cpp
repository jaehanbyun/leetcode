class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int steps = 0;
        int carry = 0;

        for (int i = n - 1; i > 0; --i) {
            int bit = s[i] - '0';

            int cur = bit + carry;
            if (cur == 0) {
                steps += 1;
            } else if (cur == 1) {
                steps += 2;
                carry = 1; 
            } else { 
                steps += 1;
                carry = 1; 
            }
        }

        if (carry == 1) {
            steps += 1;
        }

        return steps;
    }
};
