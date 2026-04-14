class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factoriesPositions;
        for (auto& f: factory) {
            for (int i=0; i<f[1]; ++i) 
                factoriesPositions.push_back(f[0]);
        }

        int robotSize = robot.size(), factorySize = factoriesPositions.size();
        vector<vector<long long>> memo(robotSize, vector<long long>(factorySize, -1));

        return calculateMinimanDistance(0, 0, robot, factoriesPositions, memo);
    }

    long long calculateMinimanDistance(int robotIdx, int factoryIdx, 
                                        vector<int>& robot, vector<int>& factoriesPositions,
                                        vector<vector<long long>>& memo) {
        if (robotIdx == robot.size()) return 0;

        if (factoryIdx == factoriesPositions.size()) return 1e12;

        if (memo[robotIdx][factoryIdx] != -1) return memo[robotIdx][factoryIdx];

        long long assign = abs(robot[robotIdx] - factoriesPositions[factoryIdx]) + 
                                calculateMinimanDistance(robotIdx+1, factoryIdx+1, robot, factoriesPositions, memo);
        
        long long skip = calculateMinimanDistance(robotIdx, factoryIdx+1, robot, factoriesPositions, memo);

        memo[robotIdx][factoryIdx] = min(assign, skip);
        return memo[robotIdx][factoryIdx];
    }
};