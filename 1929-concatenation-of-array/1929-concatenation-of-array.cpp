class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n); // Pre-allocates and zeroes out memory in 1 step

        for (int i = 0; i < n; ++i) {
            ans[i] = ans[i + n] = nums[i]; // Writes both halves in 1 pass
        }

        return ans;
    }
};