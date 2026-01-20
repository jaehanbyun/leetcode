class Leaderboard {
private:
    unordered_map<int, int> score;  // playerId -> score
    multiset<int> ms;               // all scores (sorted)

public:
    Leaderboard() {}

    void addScore(int playerId, int sc) {
        auto it = score.find(playerId);

        if (it != score.end()) {
            int old = it->second;
            auto pos = ms.find(old);     
            ms.erase(pos);               
            it->second += sc;            
            ms.insert(it->second);       
        } else {
            score[playerId] = sc;
            ms.insert(sc);
        }
    }

    int top(int K) {
        int sum = 0;
        auto it = ms.rbegin();         
        for (int i = 0; i < K; ++i, ++it) {
            sum += *it;
        }
        return sum;
    }

    void reset(int playerId) {
        int old = score[playerId];      
        auto pos = ms.find(old);
        ms.erase(pos);                   
        score.erase(playerId);           
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */