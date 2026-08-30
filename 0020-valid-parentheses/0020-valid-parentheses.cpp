class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for (auto ch : s) {
            if (st.empty()) {
                st.push(ch);
            } 
            else {
                int top = st.top(); 
                switch (ch) { 
                    case ')':
                        if(top == '(')
                            st.pop();
                        else
                            st.push(ch);
                        break;
                    case ']':
                        if(top == '[')
                            st.pop();
                        else
                            st.push(ch);
                        break;
                    case '}':
                        if(top == '{')
                            st.pop();
                        else
                            st.push(ch);
                        break;
                    default:
                        st.push(ch);
                }
            }
        }
        return (st.empty());
    }
};