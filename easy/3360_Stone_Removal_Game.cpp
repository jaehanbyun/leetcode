class Solution {
public:
    bool canAliceWin(int n) {
        bool aliceMoved = false;
        int remaining = n;
        int take = 10;
        while (take > 0 && remaining >= take) {
            remaining -= take;
            take--;
            aliceMoved = !aliceMoved;
        }
        return aliceMoved;
    }
};