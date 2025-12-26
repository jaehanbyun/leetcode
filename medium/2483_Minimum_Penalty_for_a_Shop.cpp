class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        int penalty = 0;
        // If we close at time t = 0, the shop is closed for all hours,
        // The penalty equals the number of hours with customers 'Y'. 
        for (char c: customers) {
            if (c == 'Y') penalty++;
        }

        int bestTime = 0;
        int bestPenalty = penalty;

        // Move the closing time from t to t + 1
        // Update the penalty incrementally
        for (int t = 0; t <= n; ++t) {
            if (customers[t] == 'Y') penalty--;
            else penalty++;
            
            // Record the earliest time with minimum penalty
            if (bestPenalty > penalty) {
                bestPenalty = penalty;
                bestTime = t + 1;  // closing time after processing hour t
            }
        }
       
        return bestTime;
    }
};

