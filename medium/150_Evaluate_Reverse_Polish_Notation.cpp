class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;

        int tl = tokens.size();
        vector<int> st;
        st.reserve(tl);

        for (string& t: tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int a = st.back(); st.pop_back();
                int b = st.back(); st.pop_back(); 

                if (t == "+") st.push_back(b + a);
                else if (t == "-") st.push_back(b - a);
                else if (t == "*") st.push_back(b * a);
                else st.push_back(b / a);
            }
            else st.push_back(stoi(t));
        }

        return st.back();
    }
};