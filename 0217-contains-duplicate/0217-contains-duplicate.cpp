class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dup;
        for(auto n : nums){
            if(dup.count(n))
                return true;
            else
                dup.insert(n);
        }
        return false;
    }
};