class Solution {
public:
    bool isValid(string s) {
        if (s.length()%2!=0) return false;
        std::stack<char> st;
        for (auto ch : s) {
            if (ch == '(') st.push(')');
            else if (ch == '{') st.push('}');
            else if (ch == '[') st.push(']');
            else {
                if(st.empty() || st.top() != ch) return false;
                st.pop();
            }
        }
        return (st.empty());

    }
};