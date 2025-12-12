class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);

        sort(events.begin(), events.end(),
             [](const vector<string>& a, const vector<string>& b) {
                 return stoi(a[1]) < stoi(b[1]);
             });

        vector<bool> isOnline(numberOfUsers, true);     
        vector<int> offlineUntil(numberOfUsers, -1);      

        int n = events.size();
        int i = 0;

        while (i < n) {
            int t = stoi(events[i][1]);   

            for (int u = 0; u < numberOfUsers; ++u) {
                if (!isOnline[u] && offlineUntil[u] != -1 && t >= offlineUntil[u]) {
                    isOnline[u] = true;
                    offlineUntil[u] = -1;
                }
            }

            int j = i;
            while (j < n && stoi(events[j][1]) == t) ++j;

            for (int k = i; k < j; ++k) {
                if (events[k][0] == "OFFLINE") {
                    int id = stoi(events[k][2]);
                    isOnline[id] = false;
                    offlineUntil[id] = t + 60;   
                }
            }

            for (int k = i; k < j; ++k) {
                if (events[k][0] != "MESSAGE") continue;

                string& ms = events[k][2];

                if (ms == "ALL") {
                    for (int u = 0; u < numberOfUsers; ++u) {
                        mentions[u]++;
                    }
                } else if (ms == "HERE") {
                    for (int u = 0; u < numberOfUsers; ++u) {
                        if (isOnline[u]) mentions[u]++;
                    }
                } else {
                    string token;
                    stringstream ss(ms);
                    while (ss >> token) {
                        if (token.size() >= 3 && token.rfind("id", 0) == 0) {
                            int id = stoi(token.substr(2)); 
                            mentions[id]++;
                        }
                    }
                }
            }

            i = j;  
        }

        return mentions;
    }
};
