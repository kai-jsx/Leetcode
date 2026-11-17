class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dup;
        for (auto n : nums) {
            if (!dup.insert(n).second)
                return true;
        }

        return false;
    }
};