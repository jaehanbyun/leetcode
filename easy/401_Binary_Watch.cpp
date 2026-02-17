class Solution {
public:
    vector<string> ans;
    vector<int> valH{8, 4, 2, 1};
    vector<int> valM{32, 16, 8, 4, 2, 1};
    
    void dfs(int idx, int chosen, int turnedOn, int hour, int minute) {
        if (chosen > turnedOn) return;
        if (hour > 11 || minute > 59) return;
        if (chosen + (10 - idx) < turnedOn) return;

        if (chosen == turnedOn) {
            string m = (minute < 10 ? "0" : "") + to_string(minute);
            ans.push_back(to_string(hour) + ":" + m);
            return;
        }

        // if the idx-th LED ON
        if (idx < 4) dfs(idx + 1, chosen + 1, turnedOn, hour + valH[idx], minute);
        else dfs(idx + 1, chosen + 1, turnedOn, hour, minute + valM[idx - 4]);

        // if the idx-th LED OFF
        dfs(idx + 1, chosen, turnedOn, hour, minute);
    }

    vector<string> readBinaryWatch(int turnedOn) {
        if (turnedOn >= 9) return {};

        ans.clear();
        dfs(0, 0, turnedOn, 0, 0);

        return ans;
    }
};