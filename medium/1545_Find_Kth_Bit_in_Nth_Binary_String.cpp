class Solution {
public:
    string operation(const string &in) {
        string lastParam = in;
        for (char &c : lastParam) {
            c = (c == '0') ? '1' : '0';
        }
        reverse(lastParam.begin(), lastParam.end());
        return in + "1" + lastParam;
    }

    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 2; i <= n; ++i) {  
            s = operation(s);
        }
        return s[k - 1];
    }
};