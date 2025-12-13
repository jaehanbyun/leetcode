class Solution {
public:
    static bool isValidCode(const string& s) {
        if (s.empty()) return false;
        return all_of(s.begin(), s.end(), [](unsigned char c) {
            return std::isalnum(c) || c == '_';
        });
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        static const unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<int, string>> picked;
        int n = (int)code.size();
        for (int i = 0; i < n; ++i) {
            if (!isActive[i]) continue;
            if (!isValidCode(code[i])) continue;

            auto it = order.find(businessLine[i]);
            if (it == order.end()) continue;

            picked.emplace_back(it->second, code[i]);
        }

        sort(picked.begin(), picked.end(),
             [](const auto& a, const auto& b) {
                 if (a.first != b.first) return a.first < b.first;
                 return a.second < b.second;
             });

        vector<string> res;
        res.reserve(picked.size());
        for (auto& [_, c] : picked) res.push_back(c);
        return res;
    }
};
