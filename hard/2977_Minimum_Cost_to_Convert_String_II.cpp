class Solution {
public:
    struct TrieNode {
        int nxt[26];
        int termId;
        TrieNode() : termId(-1) { fill(nxt, nxt + 26, -1); }
    };

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {
        const long long INF = (1LL<<62);
        int n = (int)source.size();

        // 1) 문자열 id 부여
        unordered_map<string,int> id;
        id.reserve(512);
        auto getId = [&](const string& s) -> int {
            auto it = id.find(s);
            if (it != id.end()) return it->second;
            int nid = (int)id.size();
            id.emplace(s, nid);
            return nid;
        };

        for (auto &s: original) getId(s);
        for (auto &s: changed)  getId(s);
        int K = (int)id.size();

        // 2) dist 초기화 + direct edge
        vector<vector<long long>> dist(K, vector<long long>(K, INF));
        for (int i = 0; i < K; i++) dist[i][i] = 0;

        for (int i = 0; i < (int)original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // 3) Floyd
        for (int k = 0; k < K; k++) {
            for (int i = 0; i < K; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < K; j++) {
                    if (dist[k][j] == INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // 4) id -> string 역매핑 후 Trie 구성
        vector<string> id2str(K);
        for (auto &kv : id) id2str[kv.second] = kv.first;

        vector<TrieNode> trie;
        trie.reserve(K * 20 + 5);
        trie.push_back(TrieNode()); // root

        auto insertTrie = [&](const string& s, int sid) {
            int cur = 0;
            for (char ch: s) {
                int c = ch - 'a';
                if (trie[cur].nxt[c] == -1) {
                    trie[cur].nxt[c] = (int)trie.size();
                    trie.push_back(TrieNode());
                }
                cur = trie[cur].nxt[c];
            }
            trie[cur].termId = sid;
        };

        for (int sid = 0; sid < K; sid++) insertTrie(id2str[sid], sid);

        // 5) DP: dp[i] = prefix 길이 i까지 최소비용
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            // 5-1) 한 글자 그대로 (source[i]==target[i])
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // 5-2) 구간 [i..j] 변환: trie를 동시에 내려감
            int pS = 0, pT = 0;
            for (int j = i; j < n; j++) {
                int cs = source[j] - 'a';
                int ct = target[j] - 'a';
                pS = trie[pS].nxt[cs];
                pT = trie[pT].nxt[ct];
                if (pS == -1 || pT == -1) break;

                int u = trie[pS].termId;
                int v = trie[pT].termId;
                if (u != -1 && v != -1 && dist[u][v] != INF) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + dist[u][v]);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
