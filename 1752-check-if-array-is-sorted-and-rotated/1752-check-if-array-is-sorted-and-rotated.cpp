class Solution {
public:
    bool check(vector<int>& nums) {
        int n = size(nums);
        int drop = 0;
        for (int i=0 ; i < n ; i++){
            if(nums[i] > nums[ (i+1) % n]) //helps check last with first element without using an if statement
                drop++;
        }
        return drop<=1;
    }
};