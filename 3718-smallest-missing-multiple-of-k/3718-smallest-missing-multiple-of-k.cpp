class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int target = k;
        while (seen.count(target)) {
            target += k; 
        }

        return target;
    }
};