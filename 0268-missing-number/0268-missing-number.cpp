class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int currentSum = 0, expectedSum = 0;
        for(auto i : nums){
            currentSum += i;
        }
        for(int i = 0; i <= nums.size(); i++){
            expectedSum += i;
        }

        return ( expectedSum - currentSum);
    }
};