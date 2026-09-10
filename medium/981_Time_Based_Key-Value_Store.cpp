class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> map;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int l = -1, r = map[key].size();
        string res = "";
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            if (map[key][mid].first <= timestamp) {
                l = mid;
                res = map[key][mid].second;
            }
            else r = mid;
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */