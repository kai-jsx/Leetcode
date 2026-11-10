class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int unique = 0;
        for( auto i : nums){
            unique ^= i;
        }
        return unique;
    }
};