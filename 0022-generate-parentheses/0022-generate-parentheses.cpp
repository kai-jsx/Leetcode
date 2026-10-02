class Solution {
public:
    void backtrack(int n, int openCount, int closeCount, string current, vector<string>& result) {
        // Base case: formed a valid string of length 2 * n
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Choice 1: Add '(' if we still have available open brackets
        if (openCount < n) {
            backtrack(n, openCount + 1, closeCount, current + "(", result);
        }

        // Choice 2: Add ')' if it won't exceed the number of open brackets
        if (closeCount < openCount) {
            backtrack(n, openCount, closeCount + 1, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n, 0, 0, "", result);
        return result;
    }
};