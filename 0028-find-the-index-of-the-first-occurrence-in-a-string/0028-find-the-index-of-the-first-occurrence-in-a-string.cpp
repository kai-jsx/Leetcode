class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m > n) return -1;

        for (int i = 0; i <= n - m; i++) {
            // Compare m characters of haystack starting at index i with needle directly (No heap memory allocation)
            if (haystack.compare(i, m, needle) == 0) {
                return i;
            }
        }
        return -1;
    }
};