class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        long long a = numerator;   
        long long b = denominator;
        bool negative = (a < 0) ^ (b < 0);
        a = llabs(a);
        b = llabs(b);

        string res;
        if (negative) res.push_back('-');
        res += to_string(a / b);

        long long rem = a % b;
        if (rem == 0) return res;            

        res.push_back('.');
        string frac;
        unordered_map<int, int> pos;  

        while (rem != 0) {
            if (pos.count(rem)) {
                int idx = pos[rem];
                string out = res;
                out.append(frac.begin(), frac.begin() + idx);
                out.push_back('(');
                out.append(frac.begin() + idx, frac.end());
                out.push_back(')');
                return out;
            }
            pos[rem] = (int)frac.size();

            rem *= 10;
            int digit = rem / b;
            frac += to_string(digit);
            rem %= b;
        }

        return res + frac;
    }
};