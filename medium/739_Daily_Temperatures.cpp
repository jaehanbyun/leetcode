class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> answer(n);

        for (int currDay=0; currDay<n; ++currDay) {
            while (!st.empty() && temperatures[st.top()] < temperatures[currDay]) {
                int prevDay = st.top(); st.pop();
                answer[prevDay] = currDay - prevDay; 
            }
            st.push(currDay);
        }

        return answer;
    }
};