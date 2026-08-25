class Solution {
private:
    // Helper function is significantly faster than unordered_map lookup
    inline int getValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

public:
    int romanToInt(string s) {
        int total = 0;
        int prevValue = 0;

        // Traverse right-to-left without looking ahead in memory
        for (int i = s.length() - 1; i >= 0; i--) {
            int currValue = getValue(s[i]);

            if (currValue < prevValue) {
                total -= currValue;
            } else {
                total += currValue;
            }

            prevValue = currValue; // Store previous character value directly
        }

        return total;
    }
};