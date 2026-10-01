class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for (int i = 0; i < s.length(); ++i) {
            int char_val = 26 - (s[i] - 'a');
            int pos = i + 1;
            total += char_val * pos;
        }
        return total;
    }
};