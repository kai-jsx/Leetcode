class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int current = 0;

        for (int num : nums) {
            if (num == 1) {
                current++;
                maxCount = max(maxCount, current); // Update max whenever current grows
            } else {
                current = 0; // Always reset streak on 0
            }
        }

        return maxCount;
    }
};