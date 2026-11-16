class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int , int> dup;
        for(auto n : nums){
            dup[n]++;
            if(dup[n] > 1)
                return true;
        }
        return false;
    }
};