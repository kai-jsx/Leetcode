class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        // 1. Size (n + 1) allows direct mapping for numbers 1 to n
        vector<int> count(n + 1, 0);

        for (int num : nums) {
            count[num]++;
        }

        int duplicate = -1, missing = -1;

        // 2. Iterate from 1 to n (ignore index 0)
        for (int i = 1; i <= n; ++i) {
            if (count[i] == 2) duplicate = i;
            if (count[i] == 0) missing = i;
        }

        // 3. Guarantees correct return order: [duplicate, missing]
        return {duplicate, missing};
    }
};