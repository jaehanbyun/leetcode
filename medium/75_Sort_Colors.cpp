/*
0: red
1: white
2: blue
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0,};
        for (int num: nums) {
            cnt[num]++;
        }
        int idx = 0;     
        for (int i=0; i<3; ++i) {
            while (cnt[i] > 0) {
                nums[idx++] = i;
                cnt[i]--;
            }
        }
    }
};