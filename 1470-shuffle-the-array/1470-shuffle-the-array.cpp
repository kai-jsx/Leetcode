class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> num;
        int i = 0, c = 0;
        while(i < n){
            num.push_back(nums[i]);
            num.push_back(nums[i+n]);
            i++;
        }
        return (num);
    }
};