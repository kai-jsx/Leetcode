class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1; 
        int suffix = 1;
        vector<int> answer(nums.size(),1);
        for(int i = 0; i < nums.size(); i++){
            answer[i] = prefix;
            prefix *= nums[i];
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        return(answer);
    }
};