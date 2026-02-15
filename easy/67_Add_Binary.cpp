class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = (int)a.size();
        int bLen = (int)b.size();
        int n = max(aLen, bLen);

        if (aLen < bLen) a = string(bLen - aLen, '0') + a;
        else if (bLen < aLen) b = string(aLen - bLen, '0') + b;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans;
        ans.reserve(n + 1);  

        int carry = 0;
        for (int i = 0; i < n; ++i) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            ans.push_back(char('0' + (sum & 1)));
            carry = (sum >> 1);
        }

        if (carry) ans.push_back('1');

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
