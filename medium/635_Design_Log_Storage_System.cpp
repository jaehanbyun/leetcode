class LogSystem {
public:
    vector<pair<string, int>> logs;
    map<string, int> g2len;

    LogSystem() {
        g2len["Year"] = 4;
        g2len["Month"] = 7;
        g2len["Day"] = 10;
        g2len["Hour"] = 13;
        g2len["Minute"] = 16;
        g2len["Second"] = 19;
    }
    
    void put(int id, string timestamp) {
        logs.push_back({timestamp, id});
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        int len = g2len[granularity];
        string startPrefix = start.substr(0, len);
        string endPrefix = end.substr(0, len);
        
        vector<int> out;
        for (auto iter=logs.begin(); iter!=logs.end(); ++iter) {
            string tsPrefix = iter->first.substr(0, len);
            if (startPrefix <= tsPrefix && tsPrefix <= endPrefix) {
                out.push_back(iter->second);
            }
        }

        return out;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */