class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixCount;
        prefixCount[0] = 1;
        int count = 0, currSum = 0;
        for(auto num : nums){
            currSum += num;
            if(prefixCount.find(currSum - k) != prefixCount.end())
                count += prefixCount[currSum - k];
            prefixCount[currSum]++;
        }

        return count;
    }
};