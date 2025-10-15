class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<pair<int, int>> spellsWithIdx;

        for (int i = 0; i < n; ++i) {
            spellsWithIdx.push_back({spells[i], i});
        }
    
        sort(spellsWithIdx.begin(), spellsWithIdx.end());
        sort(potions.begin(), potions.end());

        vector<int> ans(n, 0);
        for (auto [spell, idx]: spellsWithIdx) {
            int lo = 0, hi = m - 1, potionIdx = m + 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo)/2;
                 if ((long long)spell * (long long)potions[mid] >= success) {
                    potionIdx = mid;
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }
            if (potionIdx != m + 1) ans[idx] = m - potionIdx;
        }
    
        return ans;
    }
};