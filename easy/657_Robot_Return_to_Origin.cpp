class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontalNum = 0;
        int verticalNum = 0;
        map<char, int> h = {{'R', 1}, {'L', -1}};
        map<char, int> v = {{'U', 1}, {'D', -1}};

        for (auto &move: moves) {
            if (h.count(move)) {
                horizontalNum += h[move];
            }
            if (v.count(move)) {
                verticalNum += v[move];
            }
        }

        return horizontalNum == 0 && verticalNum == 0;
    }
};