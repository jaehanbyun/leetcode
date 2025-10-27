class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        
        for (const char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push_back(c);
            }
            else {
                if (st.size() == 0 ) return false;
                char b = st.back();
                switch (c) {
                    case ')':
                        if (b != '(') return false;
                        st.pop_back();
                        break;
                    case '}':
                        if (b != '{') return false;
                        st.pop_back();
                        break;
                    case ']':
                        if (b != '[') return false;
                        st.pop_back();
                        break;
                    default:
                        return false; 
                }
            }
        } 

        return (st.size() > 0) ? false : true;
    }
};