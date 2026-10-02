class Solution {
public:
    int maxDepth(string s) {
        std::stack<int> s1;
        int max = 0;
        for (char c : s) {
            if (c == '(') {
                s1.push(c);
            } else if (c == ')') {
                if (s1.size() > max)
                    max = s1.size();
                if (!s1.empty())
                    s1.pop();
            }
        }
        return (max);
    }
};