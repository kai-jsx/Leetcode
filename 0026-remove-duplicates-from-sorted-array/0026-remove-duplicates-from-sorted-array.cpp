class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                if (k != i) {
                    nums[k] = nums[i]; // Skip redundant self-assignment
                }
                k++;
            }
        }
        return k;
    }
};