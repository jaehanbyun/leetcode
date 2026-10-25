class Solution {
private:
    const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int toDayOfYear(const string& date) {
        int month = stoi(date.substr(0, 2));  // "08-15" → 8
        int day   = stoi(date.substr(3, 2));  // "08-15" → 15

        int total = 0;
        
        for (int i = 0; i < month - 1; ++i) {
            total += days[i];
        }
        return total + day;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int aliceStart = toDayOfYear(arriveAlice);
        int aliceEnd   = toDayOfYear(leaveAlice);
        int bobStart   = toDayOfYear(arriveBob);
        int bobEnd     = toDayOfYear(leaveBob);

        int start = max(aliceStart, bobStart);  
        int end   = min(aliceEnd, bobEnd);     

        return max(0, end - start + 1);
    }
};