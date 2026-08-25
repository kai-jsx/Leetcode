#include <vector>
#include <algorithm>

class Solution {
public:
    int missingMultiple(std::vector<int>& nums, int k) {
        // Sort the array in-place -> O(N log N) time, O(1) space
        std::sort(nums.begin(), nums.end());

        int target = k;

        for (int num : nums) {
            if (num == target) {
                target += k; // Found current target, target moves to next multiple
            } else if (num > target) {
                break; // Array is sorted; if num > target, target will never be found
            }
        }

        return target;
    }
};