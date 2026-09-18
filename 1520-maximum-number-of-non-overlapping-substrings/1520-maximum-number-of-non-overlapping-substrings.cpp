class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);

        // Step 1: Record first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int, int>> candidates;

        // Step 2: Expand candidates and prune invalid ranges
        for (int c = 0; c < 26; ++c) {
            if (first[c] == -1) continue;

            int i = first[c];
            int j = last[c];
            bool isValid = true;

            for (int k = i; k <= j; ++k) {
                int charIdx = s[k] - 'a';
                if (first[charIdx] < i) {
                    isValid = false;
                    break;
                }
                j = max(j, last[charIdx]);
            }

            if (isValid) {
                candidates.push_back({i, j});
            }
        }

        // Step 3: Sort by ending position for greedy selection
        sort(candidates.begin(), candidates.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        // Step 4: Pick non-overlapping intervals
        vector<string> result;
        int lastEnd = -1;

        for (const auto& [start, end] : candidates) {
            if (start > lastEnd) {
                result.push_back(s.substr(start, end - start + 1));
                lastEnd = end;
            }
        }

        return result;
    }
};